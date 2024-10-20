#include <stdlib.h>
#include <stdio.h>
struct Que{
    int front;
    int rear;
    int size;
    int *Q;
};
void enqueue(struct Que *q , int x){
    if((q->rear+1)%q->size == q->front){
        printf("Queue is full");
        return; 
    }
    q->rear = (q->rear + 1) % q->size;
    q->Q[q->rear] = x; 
}
int deque(struct Que *q){
    int x = -1;
    if(q->front == q->rear){
        printf("Queue is empty");
    }
    else{
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];

    }
    return x; 
}
int main(){
    struct Que q;
    q.front = q.rear = 0;
    q.size = 6;
    q.Q = (int *)malloc(sizeof(int) * q.size);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);
    enqueue(&q, 7);
    enqueue(&q, 8);
    enqueue(&q, 9);
    deque(&q);
    deque(&q);
    deque(&q);
    enqueue(&q, 9);
    

}