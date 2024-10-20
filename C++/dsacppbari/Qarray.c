#include <stdlib.h>
#include <stdio.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};
void enqueue(struct Queue *q , int x){
    if(q->front == q->size-1){
        printf("Queue is full");
        return;

    }
    q->Q[++q->rear] = x; 
}
int dequeue(struct Queue *q){
    int x = -1; 
    if(q->front == q->rear){
        printf("Queue is empty");
        return x;
    }
    return q->Q[++q->front];
}
void display(struct Queue q){
    for (int i = q.front+1; i <= q.rear; i++){
        printf("%d ", q.Q[i]);
    }
}
int main(){
    struct Queue q;
    q.size = 20;
    q.Q = (int *)malloc(sizeof(int) * q.size);
    q.front = q.rear = -1;
    enqueue(&q, 7);
    enqueue(&q, 8);
    enqueue(&q, 9);
    enqueue(&q, 10);
    dequeue(&q);
    display(q);
}