#include <stdlib.h>
#include <stdio.h>
struct Node{
    int data ; 
    struct Node* next ;
    struct Node* prev ;
};
struct Node* head = NULL;
struct Node* createNewNode(int x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x ;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;

}
void begininsert(int n ){
    struct Node* newNode = createNewNode(n);
    if(head == NULL){
        head = newNode;
        return ;
    }
    head->prev = newNode ;
    newNode->next = head ;
    head = newNode ;

}
void insert(int n , int p ){
    struct Node* insertingNode  = createNewNode(n);
    if(head==NULL){
        head = insertingNode;
        return ;

    }
    struct Node* temp1 = head ;
    for(int i = 0 ; i < p-2; i++){
        temp1 = temp1->next;
    }
    insertingNode->prev = temp1 ;
    insertingNode->next = temp1->next;
    temp1->next = insertingNode ;


}
void print(){
    struct Node* temp = head ; 
    while(temp!= NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    
    
}
void removeNode(int p){
    struct Node* temp = head ; 
    struct Node* temp1 ;
    if(p==1 ){
        head = temp->next;
        head->prev = NULL;
        free(temp);
        return ;

    }
    for(int i = 0 ; i < p-2 ; i++){
        temp = temp->next;
    }
    temp1 = temp->next;
    temp->next = temp1->next;
    free(temp1);
}


int main(){
    printf("Name : - ANUSHKA NEGI\n");
    int a , b ,c,i ; 

    
    insert(3,1);
    print();
    insert(4,2);
    print();
    begininsert(6);
    
    
    print();
    removeNode(3);
    print();



}