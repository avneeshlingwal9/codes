#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data[50];
    struct Node* next;
};
struct Node* head = NULL ;

struct Node* createNode(const char* str) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data, str);
    newNode->next = NULL;
    return newNode;
}

void insert( const char* str) {
    struct Node* newNode = createNode(str);

    if (head == NULL || strcmp(str, (head)->data) < 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL && strcmp(str, temp->next->data) > 0) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void print() {
    struct Node* temp = head;
    printf("Elements of linked list are : - \n");
    while (temp != NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
}

int main() {
    printf("NAME : - ANUSHKA NEGI \n");
    struct Node* head = NULL;
    char str[50];
insert("Apple");
insert("Banana");
insert("Orange");
print();

    return 0;
}
