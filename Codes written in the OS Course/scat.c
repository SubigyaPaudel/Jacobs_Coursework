#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <fcntl.h> // header file containing open and close calls
#include <unistd.h> // header file containing read and write calls
#include <sys/sendfile.h> //header file containing the sendfile method

void library_mode(char* source_file, char* destination_file){
    FILE* source = fopen(source_file, "r");
    FILE* destination = fopen(destination_file, "w");
    if (source == NULL || destination == NULL){
        fprintf(stderr, "Failed to open one or more files");
	    exit(1);
    }
    fseek(source, 0, SEEK_SET);
    char cursor = getc(source);
    while(cursor != EOF){
        putc(cursor, destination);
        cursor = getc(source);
    }
    printf("\nContent copied in library mode\n");
    fclose(source);
    fclose(destination);
}

void system_mode(char* source_file, char* destination_file){
    int source = open(source_file, O_RDONLY);
    int destination = open(destination_file, O_WRONLY);
    if(source == -1 || destination == -1){
        char msg[64] = "Failed to open one or mode files";
        write(2, msg, 64);
        exit(1);
    }
    int copied = 32;
    char* buffer;
    while(copied != 0){
        buffer = (char *) malloc(32 * sizeof(char));
        copied = read(source, buffer, 32);
        write(destination,buffer, strlen(buffer));
        free(buffer);
    }
    const char msg[64] = "\nCopied the files in system mode\n";
    write(1, msg, 64);
    close(source);
    close(destination); 
}

void kernel_mode(char* source_file, char* destination_file){
    int source = open(source_file, O_RDONLY);
    int destination = open(destination_file, O_WRONLY);
    if(source == -1 || destination == -1){
        char msg[64] = "Failed to open one or mode files";
        write(2, msg, 64);
        exit(1);
    }
    int copied = 8192;
    while(copied)
        copied = sendfile(destination, source, NULL, 8192);
    const char msg[64] = "\n Copied files in Kernel mode";
    write(1, msg, 64);
    close(source);
    close(destination);
}

int main(int argc, char** argv){
    int completion = 0;
    char option;
    char* source = argv[argc - 2];
    char* destination = argv[argc - 1];
    while((option = getopt(argc, argv , "lsp")) != -1){
        switch(option){
            case 'l':
                library_mode(source, destination);
                completion = 1;
                break;
            case 's':
                system_mode(source, destination);
                completion = 1;
                break;
            case 'p':
                kernel_mode(source, destination);
                completion = 1;
                break;
        }
    }
    if(completion)
        printf("\n Source: %s \n Destination: %s \n", source, destination);
    return 0;
}
