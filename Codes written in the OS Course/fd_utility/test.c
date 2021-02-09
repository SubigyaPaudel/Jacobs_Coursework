#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <fnmatch.h>
#include <math.h>
#include <limits.h>

int main(int argc, char **argv){
    FILE* file = fopen("foo", "r");
    if(feof(file)){
        printf("File empty\n");
    }
    fclose(file);
}
/*
if(chdir(root)){
        perror("Error changing the working directory\n");
        return;
    }
    DIR* here = opendir(".");
    struct dirent* file;
    while((file = readdir(here))){
        if(strcmp(file->d_name, ".") && strcmp(file->d_name, "..")){
            char path[PATH_MAX];
            strcpy(path, "");
            if(route != NULL){
                (void) strcat(path, route);
                (void) strcat(path, "/");
            }
            (void) strcat(path, file->d_name, pattern, meta_data.st_mode);
            struct stat meta_data;
            if(stat(file->d_name, &meta_data)){
                perror("STAT\n");
                continue; 
            }
            if(can_print(mask,file->d_name,)){
                printf("%s\n", path);
            }
            if(meta_data.st_mode & S_IFDIR){
                if(meta_data.st_mode & S_IXUSR){
                    iterate_directory_tree(path, file->d_name, pattern, mask);
                }else{
                    fprintf(stderr, "Permission denied to access directory %s", path);
                }
            }
        }
    }
    if(chdir("..")){
        perror("Error changing the working directory\n");
        exit(1);
    }
    closedir(here);
*/