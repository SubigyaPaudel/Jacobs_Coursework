#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv){ 
    for(; argc > 0; argc--){
        fork();
        printf("%d seconds to program termination\n", 2 * argc);
    }
    printf("Goodbye\n");
    return 0;
}