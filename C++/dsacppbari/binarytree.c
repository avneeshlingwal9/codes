#include <stdlib.h>
#include <stdio.h>
struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;

}*root = NULL;
struct Qnode{
    struct Qnode *front;
    struct Qnode *rear; 
    struct Node* data;
    struct Qnode *next; 
};
void createq(struct Qnode *q){
    q->front = (struct Qnode *)malloc(sizeof(struct Qnode));
    q->rear = q->front;
}
struct Stack{
    struct Node *address;
    struct Stack *next;

}*top = NULL;
void push(struct Node* p){
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    if(s== NULL){
        printf("Stack overflow");
        return;
    }
    s->address = p;
    s->next = top;
    top = s; 

}
struct Node* pop(){
    if( top == NULL){
        printf("Stack is empty");
        return NULL;
    }
    struct Stack *s; 
    struct Node *p;
    s = top;
    top = top->next;
    p = s->address;
    free(s);
    return p; 
}

void qpush(struct Qnode *q ,struct Node* x){
    struct Qnode *t = (struct Qnode *)malloc(sizeof(struct Qnode));
    if(t == NULL){
        printf("Queue is full");
        return;
    }
    t->data = x;
    t->next = NULL;

    q->rear->next = t;
    q->rear = t;
    

}

struct Node* qpop( struct Qnode *q){
    struct Node* x = 0;
    if(q->front == q->rear){
        printf("Queue is empty");
        
    }
    else{
        struct Qnode *p;
        p = q->front;
        q->front = q->front->next;
        x = q->front->data;
        free(p);
    }
    return x; 
}
void create(){
    struct Qnode q;
    createq(&q);
    struct Node *p, *t;
    int x;
    printf("Enter the value of root element ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    qpush(&q,root);

    while(q.front != q.rear){
        p = qpop(&q);
        printf("Enter the value of left child of %d ", p->data);
        scanf("%d", &x);
        if(x!= -1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t ; 
            qpush(&q,t);
        }
        
        printf("Enter the value of right child %d ", p->data);
        scanf("%d", &x);
        if(x != -1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            qpush(&q,t);
        }
    }
}
void preorder(struct Node* p)


{
if(p){
    printf("%d ", p->data);
    preorder(p->lchild);
    preorder(p->rchild);
}
}
void inorder(struct Node* p){
    if(p){
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}
void postorder(struct Node* p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
    }
}
void itrpreorder(struct Node* t){
    
    while(t != NULL || !top == NULL ){
        if (t != NULL){
            printf("%d ", t->data);
            push(t);
            t = t->lchild;
        }
        else{
            t = pop();
            t = t->rchild;
        }

    }
}
void itrinorder(struct Node *t){
    
    while (t != NULL || !top == NULL){
        if(t!= NULL){
            push(t);
            t = t->lchild;
        }
        else{
            t = pop();
            printf("%d ", t->data);
            t = t->rchild;
                }

    }
}
void levelorder(struct Node *t){
    struct Node *temp;
    struct Qnode q;
    createq(&q);
    printf("%d ", t->data);
    qpush(&q, t);
    while(q.front != q.rear){
        temp = qpop(&q);
        if(temp->lchild){
            printf("%d ", temp->lchild->data);
            qpush(&q, temp->lchild);
        }
        if(temp->rchild){
            printf("%d ", temp->rchild->data);
            qpush(&q,temp->rchild );
        }
        }
}
int count(struct   Node *t){
    int x = 0, y = 0;
    if(t){
        x = count(t->lchild);
        y = count(t->rchild);
        return x + y + 1;
    }
    return 0;
}
int height(struct Node *t){
    int x = 0, y = 0;
    if(t){
        x = height(t->lchild);
        y = height(t->rchild);
        if(x > y){
            return x + 1;
        }
        return y + 1;
    }
    return 0;
}
int main(){
    
    create();
    printf("IN order : ");
    inorder(root);
    printf("\nIN order: ");
    itrinorder(root);
    printf("\nLevel order: ");
    levelorder(root);
    printf("\nHeight of tree is: %d ", height(root));
    printf("\nNumber of nodes in the tree is: %d ", count(root));
}