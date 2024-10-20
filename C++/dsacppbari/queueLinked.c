#include <stdlib.h>
#include <stdio.h>

struct Node{
    int x;
    struct Node *next;
} *front = NULL, *rear= NULL; 
void enqueue(int x){
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));

    if (t == NULL){
        printf("Queue is full");
        return;
    }
    t->x = x;
    t->next = NULL;

    if(front == NULL){
        front = rear = t;

    }
    else{
        rear->next = t;
        rear = t;
    }
}
int dequeue(){
    int x = -1 ;
    struct Node *q; 
    if(front == NULL)
    {
        printf("Queue is empty");
    }
    else{
        q = front;
        front = front->next;
        x = q->x;
        q->next = NULL;
        free(q);
    }
    return x; 
}
int main(){
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    dequeue();
    dequeue();
    dequeue();
    dequeue();

}