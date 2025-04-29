#include <stdlib.h>
#include <stdio.h>
struct Node{
    int data ;
    struct Node* next ;
};
struct Node* head = NULL;
void begininsert(int x){
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x ;
    t->next = head ;
    head = t ;

}
struct Node* getnewNode(int x){
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x ;
    return t ;


}
void reverserecursion(struct Node* c , struct Node* p , struct Node* n){
    if(c== NULL){
        head = p ;
        return;
    }
    c->next = p ;
    p = c ;
    reverserecursion(n,c,c->next);

    
}
void endinsert(int x){
    struct Node* t = getnewNode(x);
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
void insertanywhere(int x , int p){
    struct Node* t = getnewNode(x);
    struct Node* temp = head ;
    if(head==NULL){
        t->next = head ;
        head = t ;
        return ;
    }
    for(int i = 0 ; i < p-2; i++){
        temp = temp->next ;

    }
    t->next = temp->next;
    temp->next = t ;





}
void reverselist(){
    struct Node* c = head , *p = NULL , *n ;
    while(c!=NULL){
        n = c->next;
        c->next = p ;
        p = c ;
        c = n ;
    }
    head = p;
}
void print(){
    struct Node* temp = head ;
    
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    int n , x ;
    printf("Enter the number of elements you want to insert in the linked list : - ");
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i ++){
        printf("Enter the element to be inserted : - ");
        scanf("%d" , &x);
        endinsert(x);
        print();
    }
    insertanywhere(5,3);
    print();
    struct Node* temp = head;
    struct Node* ne ;
    reverserecursion(temp , NULL,ne);
    print();




}