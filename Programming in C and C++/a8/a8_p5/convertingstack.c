#include <stdio.h>
#include "stack.h"

int main(){
    struct stack b;
    char sentence[30];
    fgets(sentence, sizeof(sentence), stdin);
    b = *collect(&b, sentence);
    for(int i = 0; i <= b.count ; i++){
        printf("%s\n",b.container[i]);
    }
    return 0;    
}