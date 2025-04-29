#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value) {
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = value;
    ptr->next = NULL;
    if (front == NULL) {
        front = rear = ptr;
    } else {
        rear->next = ptr;
        rear = ptr;
    }
}

int dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return -1; 
    } else {
        struct node *temp = front;
        int temp_data = front->data;
        front = front->next;
        free(temp);
        return temp_data;
    }
}

void display() {
    struct node *temp;
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("The queue is:\n");
        temp = front;
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    printf("Name : - ANUSHKA NEGI\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    int dequeued = dequeue();
    printf("Dequeued element: %d\n", dequeued);

    display();

    return 0;
}
