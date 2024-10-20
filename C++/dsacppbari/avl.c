#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
}*root = NULL;
int HeightFinder(struct Node *rt){
    int hl = rt && rt->lchild ? HeightFinder(rt->lchild) : 0;
    int hr = rt && rt->rchild ? HeightFinder(rt->rchild) : 0;
    return hl > hr ? hl + 1 : hr + 1; 
}
int BalanceFactor(struct Node* nd){
    int hl = nd && nd->lchild ? HeightFinder(nd->lchild) : 0; 
    int hr = nd && nd->rchild ? HeightFinder(nd->rchild) : 0;
    return hl - hr;
}
struct Node* LLRotation(struct Node *p){
    struct Node *pl, *plr; 
    pl = p->lchild;
    plr = pl->rchild;
    pl->rchild = p;
    p->lchild = plr;
    p->height = HeightFinder(p);
    pl->height = HeightFinder(pl);
    if(p == root){
        root = pl; 
    }
    return pl;
}
struct Node* LRRotation(struct Node *p){
    struct Node *pl = p->lchild, *plr = pl->rchild;
    p->lchild = plr->rchild;
    pl->rchild = plr->lchild;
    plr->lchild = pl;
    plr->rchild = p;
    p->height = HeightFinder(p);
    pl->height = HeightFinder(pl);
    plr->height = HeightFinder(plr);
    if(p == root){
        root = plr;
    }
    return plr; 
}
struct Node* RRRotation(struct Node *p){
    struct Node *pr, *prl;
    pr = p->rchild;
    prl = pr->lchild;
    pr->lchild = p;
    p->rchild = prl;
    p->height = HeightFinder(p);
    pr->height = HeightFinder(pr);
    if(root == p){
        root = pr;
    }
    return pr; 
}

struct Node* RLRotation(struct Node* p){
    struct Node *pr, *prl;
    pr = p->rchild;
    prl = pr->lchild;
    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;
    prl->lchild = p;
    prl->rchild = pr;
    p->height = HeightFinder(p);
    pr->height = HeightFinder(pr);
    prl->height = HeightFinder(prl);
    if(root == p){
        root = prl;
    }
    return prl;
}
struct Node* RInsert(struct Node* r , int data){
    struct Node *temp; 
    if(r == NULL){
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = data;
        temp->lchild = temp->rchild = NULL;
        temp->height = 1;
        return temp; 
    }
    if(r->data < data){
        r->rchild = RInsert(r->rchild, data);
    }
    else if(r->data > data){
        r->lchild = RInsert(r->lchild, data);
    }
    else{
        printf("Data duplicated cannot be inserted ");
        return NULL;
    }
    r->height = HeightFinder(r);
    if(BalanceFactor(r) == 2 && BalanceFactor(r->lchild) == 1){
        return LLRotation(r);
    }
    else if(BalanceFactor(r) == 2 && BalanceFactor(r->lchild) == -1){
        return LRRotation(r);
    }
    else if(BalanceFactor(r) ==-2 && BalanceFactor(r->rchild) == -1){
        return RRRotation(r);
    }
    else if(BalanceFactor(r) ==-2 && BalanceFactor(r->rchild) ==1 ){
        return RLRotation(r);
    }


    return r; 
}
void Inorder(struct Node* n){
    if(n == NULL){
        return;
    }
    Inorder(n->lchild);
    printf("%d ", n->data);
    printf("%d ", n->height);
    Inorder(n->rchild);
}

int main(){
    root = RInsert(root, 10);
    RInsert(root, 20);
    RInsert(root, 30);
    RInsert(root, 25);
    RInsert(root, 28);
    RInsert(root, 27);
    RInsert(root,5 );
    

    Inorder(root);
}