#include <stdlib.h>
#include <stdio.h>
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
} *head;

void create(int A[], int n){
    struct Node *temp, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->prev = NULL;
    head->next = NULL;
    last = head;
    for (int i = 1; i < n; i++){
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        temp->prev = last;
        last->next = temp;
        last = temp; 
    }
}
void display(struct Node *p){
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int count(struct Node *p){
    int l = 0; 
    while(p){
        l++;
        p = p->next;
    }
    return l;  
}
void insert(int pos , int x){
    if(pos <0 || pos  > count(head)){
        return;
    }
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = t->prev = NULL;
    if(pos==0){
        if(head==NULL){
            
            head = t;
        }
        else{
            t->next = head;
            head->prev = t;
            head = t;
        }
        
        
    }
    else{
        struct Node *p = head;
        for (int i = 1; i < pos; i++){
            p = p->next;
        }
        if(p->next){
        t->next = p->next;
        p->next->prev = t;
        t->prev = p;
        p->next = t;}
        else{
            t->next = p->next;
            t->prev = p;
            p->next = t;
        }
    }

}
int Delete(int pos){
    int x = -1;
    if(pos < 1 || pos > count(head)){
        return x;
    }
    struct Node *p = head;
    for (int i = 1; i < pos ; i++){
        p = p->next;
    }
    if(p == head){
        x = p->data;
        head = head->next;
        if(head){
        head->prev = NULL;}

    
        free(p);
    }
    else{

        p->prev->next = p->next;
        if(p->next){
            p->next->prev = p->prev;
            }
        x = p->data;
        free(p);
    
    }
    return x;
}
void reverse(struct Node *p){
    struct Node *temp = NULL; 
    while(p!=NULL){
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p  &&p->next == NULL)
        {
            head = p;
        }
    }
    
}
int main(){
    int A[] = {2, 4, 5, 6, 7, 8};
    create(A, 6);
    display(head);
    insert(6, 69);
    display(head);

    display(head);
    reverse(head);
    display(head);
}
