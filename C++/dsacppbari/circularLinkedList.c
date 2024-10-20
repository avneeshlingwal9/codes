#include <stdlib.h>
#include <stdio.h>
struct Node{
    int data;
    struct Node *next; 
}*head = NULL;
void create(int A[] , int n){
    struct Node *t, *l;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;
    l = head;
    for (int i = 1; i < n; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = l->next;
        l->next = t;
        l = t; 
    }

}
void display(struct Node*p ){
    do{
        printf("%d ", p->data);
        p = p->next;

    }while (p!= head);
    printf("\n");

}
void displayrecur(struct Node *p){
    static int flag = 0 ; 
    if(p != head || flag == 0){
        flag = 1;
        printf("%d ", p->data);
        displayrecur(p->next);
    }
    flag = 0;

}
int count(struct Node *p ){
    int c= 0 ;
    do{
        c++;
        p = p->next;
    } while (p!= head);
    return c; 
}
void insertion(int pos , int el){
    if(pos < 0 || pos > count(head)){
        return; 
    }
    struct Node *t, *p = head;
    if(pos == 0 ){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = el;
        if (head == NULL){
            head = t;
            head->next = head;
        }
        else{
            while(p->next!= head){
                p = p->next;
            }
            t->next = head;
            p->next = t;
            head = t; 
        }
    }
    else{
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = el;
        for (int i = 0; i < pos - 1; i++){
            p = p->next;
        }
        t->next = p->next;
        p->next = t;

    }
}
int Delete(int pos ){
    int x = -1;
    struct Node *p = head ;
    if(pos < 1 || pos > count(head)){
        return x;
    }
    if(pos ==1 ){
        while(p->next!= head){
            p = p->next; 
        }
        if(p== head){
            x = head->data;
            free(head);
            head = NULL;
        }
        else{
            p->next = head->next;
            x = head->data;
            free(head);
            head = p->next; 
        }

        
    }
    else{
        for (int i = 1; i < pos - 1; i++){
            p = p->next;
        }
        struct Node *q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
        
    }
    return x;
}
int main(){
    int A[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    create(A,9);
    display(head);
   int j =  Delete(10);
    display(head);
}