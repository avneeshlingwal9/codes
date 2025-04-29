#include <stdio.h>
#include <stdlib.h>
struct Node {
    int key;
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNewNode(int k , int x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = k;
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode ;
    
}
struct Node* head = NULL ;
void insertNode( int key, int data) {

    struct Node* newNode = createNewNode(key,data);

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->right != NULL) {
            temp = temp->right;
        }
        temp->right = newNode;
        newNode->left = temp;
    }
}


struct Node* searchNode( int key) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->key == key) {
            return temp;
        }
        temp = temp->right;
    }
    return NULL; 
}


void deleteNode( int key) {
    struct Node* d = searchNode(key);
    if (d == NULL) {
        printf("Unsuccessful Search: Key not found\n");
        return;
    }

    if (d->left != NULL) {
        d->left->right = d->right;
    } else {
        head = d->right;
    }

    if (d->right != NULL) {
        d->right->left = d->left;
    }

    free(d);
}

 
void print() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("Key is %d  . Data is  %d\n", temp->key, temp->data);
        temp = temp->right;
    }
}

int main() {
    printf("Name : - ANUSHKA NEGI\n");
    
    insertNode(4,5);
    insertNode(6,5);
    insertNode(8,1);
    print();
    deleteNode(6);
    print();




    return 0;
}
