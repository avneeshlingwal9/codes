#include <stdlib.h>
#include <stdio.h>
struct Node{
    int data ;
    struct Node *prev , *next ;
};
struct Node* head = NULL ;

struct Node* create(int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data ;
    newnode->next = NULL ;
    newnode->prev = NULL ;
    return newnode;
}
void insert(int data){
    struct Node* temp = create(data);
    if(head == NULL){
        head = temp ;}
        else {
            temp->next = head ;
            head->prev = temp ; 
            head = temp ;

            
        }
}
void display(){
    struct Node* temp = head ;
    while(temp!=NULL){
        printf("%d " , temp->data);
        temp = temp->next;

    }
    printf("\n");
    
}
void removeduplicates(){
    int se[1000] = {0} ; // Setting an array with value of each index as 0 . 
    Node* temp = head;
    while(temp != NULL){
        if(se[temp->data] == 1 ) //Checking if we have encountered the element first. 
        {
            struct Node* pr = temp->prev ;
            struct Node* ne = temp->next ;
            if(pr!=NULL){
                pr->next = ne ; // Removing the element 
                ne->prev = pr ;
                
            }
            else{
                head = ne ;  // It it is head element then set head as next element.
            }

        }
        else{
            se[temp->data] = 1 ; // If we have encountered the element we will set its index as 1. 
        }
        temp = temp->next ;

    }
}
int main(){
    insert(4);
    insert(5);
    insert(6);
    insert(6);
    insert(7);
    printf("Element before duplication removal ");
    display();
    removeduplicates();
    printf("Element after duplication removal ");
    display();
    

}