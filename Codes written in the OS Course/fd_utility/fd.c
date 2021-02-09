#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <getopt.h>
#include <sys/stat.h>
#include <fnmatch.h>
#include <limits.h>

typedef struct paths{
    char apath[PATH_MAX];
    struct paths* next;
} Paths;

int can_print(int expectation_mask, const char* filename, const char* pattern, int st_mode, int d_type){
    int matched = 0;
    if(pattern != NULL){
        matched = fnmatch(pattern, filename, 0);
        if(!matched){
            if(expectation_mask == 127)
                //checking would be pointless if every kind of file 
                //(signified by the expectation_mask being 127) is expected
                return 1;
        }else{
            if(matched != FNM_NOMATCH){ //checking for errors for fnmatch
                perror("fnmatch error\n");
                return -1;
            }
            return 0; //filename did not match the pattern and there were no errors, return a 0
        }
    }
    int filetypes[5] = {DT_REG, DT_DIR, DT_LNK, DT_FIFO, DT_SOCK};
    /*checking if the file is either
        - A regular file
        - A directory
        - A symbolic link
        - A named pipe
        - A local-domain socket
    */
    for(int i = 0; i < 5; i++){
        if(expectation_mask & (1 << i) && filetypes[i] == d_type){
            return 1;
        }
    }
    /*
        This block only runs if the above block couldn't confirm 
        whether the file can be printed or not
    */
    int filetype = st_mode;
    if(expectation_mask & (1<<6)){
    //Checking if a file is an executable
        if(filetype & S_IXUSR || filetype & S_IXGRP || filetype & S_IXOTH)
            return 1;
    }else if(expectation_mask & (1<<5)){
        //Checking if the file is empty
        if(d_type == DT_REG){
            int fd = open(filename, O_RDONLY);
            if(fd != -1){
                char buffer[64];
                int scanned = read(fd, buffer, 64);
                close(fd);
                if(scanned == 0){
                    return 1;
                }else if(scanned == -1){
                    perror("Failed to check for an empty file");
                }
            }else{
                perror("Failed to check for an empty file");
                return -1;
            }
        }
    }
    return 0;
}

void iterate_directory_tree(char* route, char* root, const char* pattern, int mask){
    if(chdir(root)){
        perror("Error changing the working directory\n");
        return;
    }
    DIR* here = opendir(".");
    struct dirent* file;
    while((file = readdir(here))){
        if(strcmp(file->d_name, ".") && strcmp(file->d_name, "..")){
            // .  and .. are just another aliases of the parent directory and the current directory, and must be avoided if
            // the program is to perform a depth-first-search of the tree whose root is defined by the argument root
            char path[PATH_MAX];
            strcpy(path, "");
            if(route != NULL){
                (void) strcat(path, route);
                (void) strcat(path, "/");
            }
            (void) strcat(path, file->d_name);
            struct stat meta_data;
            if(stat(file->d_name, &meta_data)){
                perror("STAT\n");
                continue; 
            }
            int check = can_print(mask,file->d_name, pattern, meta_data.st_mode, file->d_type);
            // check if the file is the desired type by looking at the output of the can_print
            // function, which considers the parameters that we passed in the command line
            // whilst running this function
            if(check != 0 && check != -1){
                printf("%s\n", path);
            }
            if(meta_data.st_mode & S_IFDIR){
                if(meta_data.st_mode & S_IXUSR){
                    iterate_directory_tree(path, file->d_name, pattern, mask);
                    // perform a dfs visit if this directory entry is a file
                }else{
                    fprintf(stderr, "Permission denied to access directory %s", path);
                    //can't change to this directory because the execution permissions lack
                }
            }
        }
    }
    if(chdir("..")){
        //change back to the parent directory once you are done iterating through the entries of the current directory
        perror("Error changing the working directory\n");
        exit(1);
    }
    closedir(here);
}

int main(int argc, char* argv[]){
    Paths *cursor, *begin = NULL;
    char option, pattern[256], path[512];
    strcpy(pattern, "\0");
    strcpy(path, "\0");
    int tmask = 0;
    int args = 1;
    while((option = getopt(argc, argv, "t:")) != -1){
        char value = optarg[0];
        switch(value){
            case 'f':
                printf("Regular file being searched for\n");
                tmask |= 1 << 0;
                break;
            case 'd':
                printf("Directory being searched for\n");
                tmask |= 1 << 1;
                break;
            case 'l':
                printf("Symbolic being searched for\n");
                tmask |= 1 << 2;
                break;
            case 'p':
                printf("Pipes being searched for\n");
                tmask |= 1 << 3;
                break;
            case 's':
                printf("Sockets being searched for\n");
                tmask |= 1 << 4;
                break;
            case 'e':
                printf("Empty files being searched for\n");
                tmask |= 1 << 5;
                break;
            case 'x':
                printf("Executables being searched for\n");
                tmask |= 1 << 6;
                break;
            default:
                fprintf(stderr, "Invalid value of t, %c\n", value);
                break;
        }
        args += 2;
    }
    if(!tmask){
        tmask = 127;
    }
    while(args < argc){
        if(!strlen(pattern)){
            // The argument after the file type is always assumed to be the pattern followed by the file name
            // So when we enter the loop for the first time then the value of pattern is '\0' making its length 0
            //hence making this condition true, and hence the code in this if branch gets executed
            strcpy(pattern, argv[args]);
            args++;
        }else{
            // The arguments that follow that pattern will be assumed to the the roots of the trees of files/directory that the
            // fd utility is going to search for. Hence we make a link list of these paths
            Paths* new = (Paths*) malloc(sizeof(Paths));
            if(new == NULL){
                perror("Malloc error!!\n");
                return EXIT_FAILURE;
            }
            strcpy(new->apath,argv[args]);
            args++;
            new->next = begin;
            begin = new;
        }
    }
    if(!strlen(pattern)){
        // if the pattern was not set, set the pattern to *
        strcpy(pattern,"*");
    }
    if(begin != NULL){
        cursor = begin;
    }else{
        cursor = (Paths*) malloc(sizeof(Paths));
        if(cursor == NULL){
            perror("Unable to allocate memory");
            return EXIT_FAILURE;
        }
        cursor->next = begin;
        strcpy(cursor->apath, ".");
    }
    char cwd[PATH_MAX]; //variable to store the absolute path of the current working directory
    if(getcwd(cwd, PATH_MAX) == NULL){
        perror("Couldn't determine working directory\n");
        return EXIT_FAILURE;
    }
    while(cursor != NULL){
        printf("\tDoing a lookup in %s\n", cursor->apath);
        iterate_directory_tree(NULL,cursor->apath, pattern, tmask);
        // the above function does a 
        if(chdir(cwd)){
            perror("Error changing the working directory\n");
            return EXIT_FAILURE;
        }
        cursor = cursor->next;
    }    
    cursor = begin;
    while(cursor != NULL){
        Paths* dummy = cursor;
        cursor = cursor->next;
        free(dummy);
    }
    return 0;
}