#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Node{
    int exp;
    int coeff;
    struct Node *next; 

} *head;
void create( int terms ){
    struct Node *last, *temp; 
    printf("Enter coefficient and exponents");
    for (int i = 0; i < terms; i++){
        temp = (struct Node *)malloc(sizeof(struct Node));
             scanf("%d%d", &temp->coeff, &temp->exp);
             temp->next = NULL;

        if(head == NULL){
         
         last = head=temp; 
         }
         else{
        
             
            last->next = temp;
            last = temp;}
         


    
}}
void display(struct Node *p ){
    while(p){
        printf("%d*x^%d + ", p->coeff,p->exp);
        p = p->next;
    }

}
int calculate(struct Node *p , int x){
    int result = 0;
    while(p){
        result = result + p->coeff * pow(x, p->exp);
        p = p->next;
    }
    return result;
}
int main(){
    create(5);
    display(head);
    printf("%d", calculate(head,1));
}