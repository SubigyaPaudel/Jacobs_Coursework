 #include <stdio.h>
 #include <stdlib.h>

 typedef struct stream{
     char c;
     struct stream* next;
 } Stream;

typedef struct queue{
     Stream *front;
     Stream*rear;
     int items; 
 } Queue;

 int main(){
     int d;
     int i = 0;
     Stream *p, *q, *Start, *removal;
     do{
        printf("Enter an ASCII Code\n");
        scanf("%d",&d);
        getchar();
        if(d < 0){
            p->next = NULL; 
            break;
        }else if(i == 0){
            Start = (Stream*) malloc(sizeof(Stream));
            Start->c = d;
            Start->next = NULL;
            p = Start;
            i++;
        }else{
            q = (Stream*) malloc(sizeof(Stream));
            q->c = d;
            p->next = q;
            p = q;
        }
     }while(1);
     while(Start != NULL){
         printf("%c",Start->c);
         removal = Start;
         Start = Start->next;
         free(removal);
     }
     printf("\n");
     return 0;
 }