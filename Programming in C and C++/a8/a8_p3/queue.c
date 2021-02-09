
 
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
 
void initialize_queue(Queue *pq)
{
    pq->front = pq->rear = NULL;
    pq->items = 0;
}
 
int queue_is_full(const Queue *pq)
{
    return pq->items == MAXQUEUE;
}
 
int queue_is_empty(const Queue *pq)
{
    return pq->items == 0;
}
 
int queue_item_count(const Queue *pq)
{
    return pq->items;
}
 
int enqueue(Item item, Queue *pq)
{    
    Node* new = (Node*) malloc(sizeof(Node));
    if (new == NULL){
        return -1;
    }
    new->item = item;
    new->next = NULL;
    if(queue_is_empty(pq)){
        pq->front = new;
        pq->rear = new;
        (pq->items)++;
        return 0;
    }else{
        pq->rear->next = new;
        pq->rear = new;
        (pq->items)++;
        return 0;
    }
}
 
int dequeue(Item *pitem, Queue *pq){
    Node *pawn;
    if(queue_is_empty(pq)){
        printf("Queue is empty, nothing to delete");
        return 0;
    }else{
        *pitem = pq->front->item;
        pawn = pq->front;
        pq->front = pq->front->next;
        printf("Removing %d from queue\n",*pitem);
        free(pawn);
        (pq->items)--;
        return 0; 
    }
}
 
void empty_queue(Queue *pq){
    Node *pawn;
    while (!queue_is_empty(pq)) {
       pawn = pq->front;
        pq->front = pq->front->next;
        free(pawn);
        (pq->items)--;
    }
}

void printq(Queue *pq){
    Node *r = pq->front;
    while(r != NULL){
        printf("%d ", (int) r->item);
        r = r->next;
    }
    printf("\n");
}