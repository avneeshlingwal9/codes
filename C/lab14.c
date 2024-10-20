#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insert(int x){
    struct Node* t = createNode(x);
    struct Node* temp = head;
    if(head == NULL){
        t->next = head ;
        head = t ;
        return ;
    }
    while(temp->next!=NULL){
        temp = temp->next ;

    }
    t->next = temp->next;
    temp->next = t ;
    

}


struct Node* searchNode( int value) {
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == value) {
            return temp; 
        }
        temp = temp->next;
    }

    return NULL; 
}


void print() {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }


}

int main() {
    printf("Name : - ANUSHKA NEGI\n");
    struct Node* foundNode = NULL;
    int sear;

    insert(10);
    insert(20);
    insert(30);
    insert(40);

    printf("Linked List:\n");
    print();

    printf("\nEnter a value to search: ");
    scanf("%d", &sear);

    foundNode = searchNode( sear);

    if (foundNode != NULL) {
        printf("Node found ");
    } else {
        printf("Node does not exist in list ");
    }

    
}
