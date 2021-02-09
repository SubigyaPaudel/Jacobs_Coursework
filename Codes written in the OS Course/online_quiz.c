#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

char* read_string;

typedef struct json{
    char question[1024];
    long number;
} JSON;

char* readall(int fd){
    int scanned = 0, total = 0;
    char buffer[64];
    int reserve = 1024;
    FILE* alter = fdopen(fd, "r");
    do{
        scanned = read(fd, buffer, 63);
        if(ferror(alter)){
            perror("Error in the file stream\n");
            exit(1);
        }else{ 
            total += scanned;
            if(total >= reserve){ //reallocate memory only if needed
                char* read_string = (char*) realloc(read_string, 2 * (reserve) * sizeof(char));
                if(read_string == NULL){
                    perror("realloc failed\n");
                    exit(1);
                }
                reserve += 2;
            }
            read_string[total] = '\0'; 
            buffer[scanned] = '\0';
            strcat(read_string, buffer);
        }
    }while(scanned);
    return read_string;
}

char* fetch(){
    int pfd[2];
    if(pipe(pfd) == -1){
        perror("Pipe creation failed\n");
        exit(1);
    }
    pid_t pid = fork();
    if(pid == -1){
        perror("Unable to create a child process\n");
        exit(1);
    }
    if(pid == 0){
        if(dup2(pfd[1], STDOUT_FILENO) == -1){ //setting the write end of the pipe as the stdout of 
                                                // the child process
            perror("dup failed");
            exit(1);
        }
        (void) close(pfd[0]);
        (void) close(pfd[1]);
        char* const arguments[4] =  {"curl", "-s", "http://numbersapi.com/random/math?min=1&max=100&fragment&json", NULL};
        execvp("curl", arguments);
        perror("exec function failed\n");
        exit(1);
    }else{
        (void) close(pfd[1]);
        char* workingstringd_info = readall(pfd[0]); //reading all the data from the read end of the pipe
        (void) close(pfd[0]);
        return workingstringd_info;
    }
}

void json_parser(char* string, JSON* data){
    int pos = 0, index = 0;
    char workingstring[1024];
    strcpy(workingstring, " ");
    for(int i = 0; i < 3; i++){
        while(string[pos] != '\0' && string[pos] != '\n'){
            workingstring[++index] = string[++pos];
        }
        pos++;
        workingstring[index] = '\0';
        switch(i){
            case 1:
                for(int i = 10; i < strlen(workingstring); i++){
                    workingstring[i-10] = workingstring[i];
                }
                workingstring[strlen(workingstring) - 12] = '\0';
                strcpy(data->question, workingstring);
                break;
            case 2:
                for(int i = 11; i < strlen(workingstring); i++){
                    workingstring[i-11] = workingstring[i];
                }
                workingstring[strlen(workingstring) - 12] = '\0';
                data->number =  (long) atoi(workingstring);
                break;
        }
        index = 0;
        strcpy(workingstring, " ");
    }
}

unsigned int play(unsigned int questionumber, unsigned int score, char* question, long answer){
    unsigned int point = 8;
    long userresponse;
    int correct = 0;
    while(point && !correct){
        printf("Q%d: %s\n", questionumber, question);
        printf("%d pt>", point);
        scanf("%ld",&userresponse);
        if(feof(stdin)){
            return 0;
        }else{
            if(userresponse < 0 || userresponse > 100){
                printf("Invalid input!!\n");
                continue;
            }
            if(userresponse == answer){
                printf("Congratulations your answer %ld is correct\n", userresponse);
                correct = 1;
            }else{
                if(point == 1){
                    if(userresponse > answer)
                        printf("Too large, the correct answer was %ld \n", answer);
                    else
                        printf("Too small, the correct answer was %ld \n", answer);
                }else{
                    if(userresponse > answer)
                        printf("Too large, try again\n");
                    else
                        printf("Too small try again\n");
                }
            }
            if(!correct){
                point /= 2;
            }
        }
    }
    return point;
}

int main(int argc, char* argv[]){
    JSON QA;
    unsigned int score = 0;
    unsigned int questionnumber = 1;
    while(!feof(stdin)){
        read_string = (char*) malloc(1024 * sizeof(char));
        read_string = fetch();
        FILE *cheat = fopen("cheat.txt", "w");
        json_parser(read_string, &QA);
        fprintf(cheat, "JSON format: %s \n\n\nquestion: %s \nanswer: %ld\n", read_string, QA.question, QA.number);
        fclose(cheat);
        score += play(questionnumber, score, QA.question, QA.number);
        printf("Your total score is %d/%d\n", score, 8*questionnumber);
        free(read_string);
        questionnumber++;
    }
    return 0;
}