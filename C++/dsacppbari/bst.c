#include <stdlib.h>
#include <stdio.h>
struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
    
}*root = NULL;
struct Node* rinsert(struct Node *r , int x){
    struct Node *temp; 
    if(r == NULL){
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = x ;
        temp->lchild = temp->rchild = NULL;
        return temp;
    }
    if(r->data > x){
        r->lchild = rinsert(r->lchild, x);
    }
    else if(r->data < x){
        r->rchild = rinsert(r->rchild, x);
    }
    return r; 
}
void insert(int x){
    struct Node *p, *t, *prev;
    t = root;
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = x;
    p->lchild = p->rchild = NULL;
    if(root == NULL)
    {
        root = p;
        return;
    }
    while(t){
        prev = t; 
        if(t->data > x){
            t = t->lchild;
        }
        else if(t->data < x){
            t = t->rchild;
        }
        else{
            return; 
        }

    }
    if(prev->data < x){
        prev->rchild = p;
        return;

    }
    prev->lchild = p;
}
void inorder(struct Node *p){
    if(p){
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
    return; 
}
struct Node* searc(int x){
    struct Node *temp = root;
    while(temp){
        if(temp->data < x){
            temp = temp->rchild;
        }
        else if(temp->data > x){
            temp = temp->lchild;
        }
        else{
            return temp;
        }

    }
    return NULL;
}
int height(struct Node* h){
    if(h == NULL){
        return 0;
    }
    int x = height(h->lchild);
    int y = height(h->rchild);
    return x > y ? x + 1 : y + 1;
}
struct Node* pred(struct Node *r){
    while(r && r->rchild!= NULL){
        r = r->rchild;
    }
    return r;
}
struct Node* suce(struct Node* q){
    while(q && q->lchild!= NULL){
        q = q->lchild;
    }
    return q;
}
struct Node* Delete(struct Node* r , int x){
    struct Node *q; 
    if(r == NULL){
        return NULL;
    }
    if(r->lchild == NULL && r->rchild == NULL){
        if(r==root){
            root = NULL;
        }
        free(r);
        return NULL;
    }
    if(x < r->data){
        r->lchild = Delete(r->lchild, x);

    }
    else if(x> r->data){
        r->rchild = Delete(r->rchild, x);
    }
    else{
        if(height(r->lchild) > height(r->rchild)){
            q = suce(r->rchild);
            r->data = q->data;
            r->rchild = Delete(r->rchild, q->data);
        }
        else{
            q = suce(r->lchild);
            r->data = q->data;
            r->lchild = Delete(r->lchild, q->data);
        }

    }
    return r; 
}
int main(){
    root = rinsert(root,67);
    rinsert(root,65);
    rinsert(root,66);
    rinsert(root,69);
    rinsert(root,70);
    rinsert(root,7);
    rinsert(root,6);

    printf("Height %d \n",height(root) );
    inorder(root);
    printf("\n");
    Delete(root,7);
    inorder(root);
    struct Node *src = searc(60);
    if(src){
        printf("Element found");
    }
    else{
        printf("Element not found");
    }
}