#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;

    if (top == NULL) {
        temp->next = NULL;
        top = temp;
    } else {
        temp->next = top;
        top = temp;
    }
}

int pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1; 
    }

    int item = top->data;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return item;
}

int isEmpty() {
    if (top == NULL) {
        return 1;
    }
    return 0;
}

void display() {
    struct Node* temp = top;
    if (temp == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Printing Stack elements\n");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    printf("Name : - ANUSHKA NEGI\n");
    push(10);
    push(20);
    push(30);

    display();

    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());

    display();

    return 0;
}
