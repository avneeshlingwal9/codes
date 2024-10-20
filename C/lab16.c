#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL ;
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertNode( int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        newNode->next = newNode; 
        head = newNode;
    } else {
        struct Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->next = head;
    }
}


void deleteNode( int data) {
    if (head == NULL) {
        printf("Circular linked list is empty.\n");
        return;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    while (current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current->next == head && prev == NULL) {
        head = NULL;
        free(current);
    }
    else if (current == head) {
        struct Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        head = current->next;
        tail->next = head;
        free(current);
    }
    else {
        prev->next = current->next;
        free(current);
    }
}
void displayList() {
    struct Node* current = head;


    do {
        printf("%d  ", current->data);
        current = current->next;
    } while (current != head);

}

int main() {
    printf("Name : - ANUSHKA NEGI\n");
    int n ; 
    for(int i = 0 ; i < 4 ; i++){
        scanf("%d",&n);
        insertNode(n);

    }
    displayList();


    return 0;
}
