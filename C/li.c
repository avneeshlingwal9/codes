#include <stdlib.h>
#include <stdio.h>
struct Node{
    int data ; 
    struct Node* next ;
};
struct Node* create(int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
void begininsert(struct Node** head ,int n ){
    struct Node* newnode = create(n);
    newnode->next = *head ;
    *head = newnode;

}


void print(struct Node* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp ) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}



struct  Node* sum(struct Node* h1 , struct Node* h2)
{
    struct Node* result = NULL; // Initializing a new node 
    
    int carry = 0 ;
    
    while(h1 !=NULL && h2!= NULL) // When none of the list is empty 
    {
        int val1 = h1->data ;
        int val2 = h2->data ;
        int total = val1+val2 + carry ;
        total = total%10 ;
        carry = total/10 ;
        begininsert(&result,total);
        h1 = h1->next;
        h2 = h2->next;
    }
    while(h1!=NULL) // if list 2 is empty then add the element from linked list and carry and add into the result .
     {
        int val1 = h1->data ;
        int total = val1+carry ;
        total = total%10;
        carry = carry/10 ;
        begininsert(&result,total);
        h1 = h1->next;
    }
    while(h2!=NULL) // It list 1 empty then add the element from linked list and add into result with carry .
    { 
        int val2 = h2->data;
        int total = val2+carry;
        total = total%10 ;
        carry = carry/10 ;
        begininsert(&result,total);
        h2 = h2->next;
    }
    if(carry>0){ // If carry is still left then add it .
        begininsert(&result,carry);
    }
    return result;   
}

int main(){
    struct Node* h1 = NULL ;
    struct Node* h2 = NULL;
    begininsert(&h1,4);
    begininsert(&h2,4);
    print(h1);
    print(h2);
    struct Node* s = sum(h1,h2);
    print(s);

    


}