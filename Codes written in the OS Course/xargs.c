//security copy of xargs.c

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <sys/wait.h>

void new_process(char* command, char** args, int arglist_max, int* modes){
    if(modes[1]){
        for(int i = 0; i < arglist_max - 1; i++){
            if(args[i] == NULL) break;
            fprintf(stderr, "%s ", args[i]);
        }
        fprintf(stderr, "\n");
    }
    pid_t id = fork();
    if(id == -1){
        perror("Fork failed");
        exit(1);
    }
    if(id > 0){
        int status;
        waitpid(id,&status,0);
    }
    if(id == 0){
        execvp(command,args);
    }
}

int main(int argc, char** argv){
    int arguments = 1; //represents the number of command line arguments we have encountered so far
    int fixed_arguments = 0; // represents the number of arguments that will stay 
                            // constant on the array provided to child processes
    int n = 1;
    char option;
    int mode[2] = {0,0};
    while((option = getopt(argc, argv, "tn")) != -1){
        switch(option){
            case 't':
                mode[1] = 1;
                arguments++;
                break;
            case 'n':
                arguments++;
                n = atoi(argv[arguments]);
                arguments++;
        }
    }
    int unprocessed_arguments = argc - arguments;   // represents the number of arguments associated with
                                                    // a command, if a command is provided through the command line
    int process_arguments_size; //represents the number of arguments passed to the child process while it changes
                                //its process image
    if(!unprocessed_arguments){
        process_arguments_size = n + 2; // n+1 for the argv for the new process image of the child
                                        // 1 for terminating the argument list with null 
        fixed_arguments = 1;
    }else{
        process_arguments_size = n + 1 + unprocessed_arguments;
                                        // 1 for terminating the argument list with mull
                                        // unprocess_arguments for the "fixed arguments"
                                        // n char pointers form the rest of the argv of the given command
    }
    char** process_arguments = (char**) malloc(sizeof(char*) * process_arguments_size);
    if(process_arguments == NULL){
        perror("Memory allocation failed\n");
        exit(1);
    }
    for(int i = 0; i < process_arguments_size; i++){
        process_arguments[i] = (char*) malloc(sizeof(char) * 64);
        if(process_arguments[i] == NULL){
            perror("Memory allocation failed\n");
            exit(1);
        }
    }
    if(!unprocessed_arguments)
        strcpy(process_arguments[0],"echo");
    while(unprocessed_arguments){
        strcpy(process_arguments[fixed_arguments], argv[arguments]);
        fixed_arguments++;
        arguments++;
        unprocessed_arguments--;
    }
    process_arguments[process_arguments_size - 1] = NULL;
    int signal = 0;
    char* buffer = (char*) malloc(sizeof(char) * 64);
    size_t buffersize = 64;
    while(signal >= 0){
        for(int i = fixed_arguments; i < process_arguments_size - 1; i++){
            signal = getline(&buffer, &buffersize, stdin);
            if(signal == -1){
                process_arguments[i] = NULL;
                break; // setting the value of the argument that was supposed to fill
                        //this position with NULL to mark the end of the argument list
            }else{
                buffer[strlen(buffer) - 1] = '\0';
                strcpy(process_arguments[i],buffer);
            }
        }
        new_process(process_arguments[0],process_arguments,process_arguments_size,mode);
    }
    for(int i = 0; i < process_arguments_size; i++)
        free(process_arguments[i]);
    free(process_arguments);
    free(buffer);
    return 0;
}