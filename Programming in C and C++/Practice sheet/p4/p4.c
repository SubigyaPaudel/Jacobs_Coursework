#include <stdio.h>
#include <string.h>

int password_checker(char* passowrd);

int main(){
    char password[256];
    int digits = 0;
    printf("Enter a password \n");
    fgets(password, sizeof(password), stdin);
    if(password_checker(password) == 1){
        printf("The password is good");
    }else{
        printf("The password is not good");
    }
    return 0;
}


int password_checker(char* password){
    int digits = 0;
    for(int i = 0; i < strlen(password); i++){
        if(password[i] >= 48 && password[i] <= 57)
            digits++;
    }
    if((digits > 2) && strlen(password) >= 8){
        return 1;
    }else{
        return 0;
    }
}