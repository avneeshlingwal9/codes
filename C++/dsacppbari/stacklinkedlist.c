#include <stdlib.h>
#include <stdio.h>
struct Node{
    int data;
    struct Node *next; 

}*Top = NULL;
void push(int x){
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("Stack overflow");
    }
    else{
        t->data = x;
        t->next = Top;
        Top = t; 
    }

}
int pop(){
    int x = -1;
    struct Node *p; 
    if(Top == NULL){
        printf("Stack underflow");
    }
    else{
        p = Top;
        Top = Top->next;
        x = p->data;
        free(p);
    }
    return x; 
}
int peek(int pos){
    struct Node *p = Top;
    for (int i = 1; i < pos && p; i++){
        p = p->next;
    }
    return p ? p->data : -1;
}
int op(){
    return Top ? Top->data : -1; 
}
int isFull(){
    struct Node *t = (struct Node)malloc(sizeof(struct Node));

    return t ? 1 : 0;
}

int isEmpty(){
    return Top ? 0 : 1; 
}

int main(){
    push(3);
    push(6);
    push(9);
    push(63);
    push(69);
    pop();
    printf("%d", peek(3));
    pop();
    pop();
    pop();
    pop();
    pop();
}