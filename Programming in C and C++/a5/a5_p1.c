#include <stdio.h>

void triangle(char ch, int n){
    for(int i = n; i >= 1; i--){
        for(int j = 1 ; j <= i; j++){
            printf("%c",ch);
        }
        printf("\n");
    }

}

int main(){
    char character;
    int number;
    scanf("%d",&number);
    getchar();
    scanf("%c",&character);
    triangle(character,number);
    return 0;
}
