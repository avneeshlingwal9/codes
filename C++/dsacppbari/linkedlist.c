#include <stdlib.h>
#include <stdio.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *head = NULL, *last = NULL, *first = NULL, *second = NULL, *third = NULL ;

struct Node* create(int data){
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    return n; 
}
void insertfirst(struct Node *n  ){
    n->next = head;

    head = n; 
}
void insertany( int pos, int el){
    struct Node *t, *p;
    if(pos==0){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = el;
        t->next = head; 
        head = t; 
    }
    else if(pos >0){
        
        p = head;
     
        for (int i = 1; i < pos && p; i++){
            p = p->next;
        }
        if(p){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = el;
            t->next = p->next;
            p->next = t; 
        }
    }

}
void createfromarray(int A[] , int n){
    struct Node *temp , *l;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;
    l = head;
    for (int i = 1; i < n; i++){
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        l->next = temp;
        l = temp;
    }

}
void createfromarray2(int A[] , int n){
    struct Node *temp , *l;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    l = first;
    for (int i = 1; i < n; i++){
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        l->next = temp;
        l = temp;
    }

}
void display(struct Node* p ){
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void recurdisplay(struct Node* p ){
    if(p!= NULL){
        printf("%d ", p->data);
        recurdisplay(p->next);
    }
    printf("\n");
}
void reverdisplay(struct Node* p){
    if(p!=NULL){
        reverdisplay(p->next);
        printf("%d ", p->data);
    }
    printf("\n");
}
int icount(struct Node* p ){
    int c = 0;
    while(p){
        c++;
        p = p->next;
    }
    return c; 
}
int rcount(struct Node* p){
    if(p){
        return 1 + rcount(p->next);
    }
    return 0; 
}
int isum(struct Node* p){
    int s = 0;
    while(p){
        s += p->data;
        p = p->next;
    }
    return s;
}
int rsum(struct Node* p ){
    if(p){
        return p->data + rsum(p->next);
    }

    return 0; 
}
void search(struct Node* p , int el){
    int index = 0,f= 0;
    while(p){
        if(p->data == el){
            f = 1;

            break;
        }
        else{
            index++;
            p = p->next;
        }
    }
    if(f){
        printf("\nElement found at index %d ", index);
    }
    else{
        printf("\nElement not found ");
            }
}
int imax(struct Node* p ){
    int m = INT_MIN;
    while(p){
        if(p->data > m ){
            m = p->data;
        }
        p = p->next;
    }
    return m; 
}
int imin(struct Node* p ){
    int m = INT_MAX;
    while(p){
        if(p->data < m ){
            m = p->data;
        }
        p = p->next;
    }
    return m; 
}


int rmax(struct Node* p){
    int x = INT_MIN;
    if(p == NULL){
        return INT_MIN;
    }
    x = rmax(p->next);
    return x > p->data ? x : p->data; 
}
int rmin(struct Node* p){
    int x = 0;
    if(p == NULL){
        return INT_MAX;
    }
    x = rmin(p->next);
    return x > p->data ? p->data : x; 
}
struct Node* improveSearch(struct Node*p , int el){
    struct Node *q = NULL; // Tail Pointer 
    while(p){
        if(p->data == el){
            q->next = p->next;
            p->next = head;
            head = p; 

            return p; 
        }
        q = p;
        p = p->next;
    }
    return NULL;
}
struct Node* iLinearSearch(struct Node*p , int k){
    while(p){
        if(p->data == k){
            return p;
        }
        p = p->next;
    }
    return NULL;
}
struct Node* rLinearSearch(struct Node* p , int k){
    if(p == NULL)
    {
        return p;
    }
    if(p->data == k)
    {
        return p; 
    }
    return rLinearSearch(p->next, k);
}
void insertAtLast(int x){
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(head == NULL){
        head = last = t; 
    }
    else{
        last->next = t;
        last = t; 
    }
}
void insertionSortedT(int x){
    struct Node *t, *p = head, *q = NULL;
    if(p->data > x){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = head; 
        head = t;
        return;
    }
    while(p && p->data < x){
        q = p;
        p = p->next;

    }
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = q->next;
    q->next = t; 
}
void insertionSortedO(int x){
    struct Node *t, *p = head;
    if(p->data > x){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = head; 
        head = t;
        return;
    }
    while(p && (p->next)->data < x){
        
        p = p->next;

    }
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = p->next;
    p->next = t; 
}
int Delete(int pos){
    struct Node *p = head, *q = NULL;
    int x= -1 , i; 
    if(pos == 1){
        head = head->next;
        x = p->data;
        free(p);
    }
    else{
        for (i = 1; i < pos && p; i++){
            q = p;
            p = p->next;
        }
        if(p){
            q->next = p->next;
            x = p->data;
            free(p);
        }

    }
    return x;
}
int isSorted(struct Node* p){
    
    int m = INT_MIN;
    while(p){
        if(p->data < m)
        {
            return 0;
        }
        m = p->data;
        p = p->next;
    }
    return 1;
}
void removeDuplicates(struct Node *p){
    struct Node *q = p->next;
    while (q != NULL){
        if(p->data != q->data){
            p = q;
            q = q->next;
        }
        else{
            p->next = q->next;
            free(q);
            q = p->next;
        }

    }
}
void removeDuplicatesO(struct Node* p){
    while(p->next){
        if(p->data != (p->next)->data){
            p = p->next;
        }
        else{
            struct Node *temp = p->next;

            p->next = p->next->next;
            free(temp);
        }
    }
}
void reversingElements(struct Node* p){
    int *A = (int *)malloc(sizeof(int) * icount(p));
    int i = 0; 
    while(p!=NULL)
    {
        A[i++] = p->data;
        p = p->next;
    }
    p = head;
    i--;
    while (p != NULL){
        p->data = A[i--];
        p = p->next;
    }


}
void reversingLinks(struct Node* q , struct Node* p){
    if (p != NULL){
        reversingLinks(p , p->next);
        p->next = q;
    }
    else{
        head = q;
    }
}
void reversingLinksIterative(struct Node* p){
    struct Node *q = NULL, *r = NULL;
    while(p != NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
}
head = q;
}
void concat(struct Node* f , struct Node* s){
    while(f->next != NULL){
        f = f->next;
    }
    f->next = s;
    s = NULL;
    free(s);
}
void merging(struct Node* f , struct Node* s){
    if(f->data < s->data ){
        last = third = f;
        f = f->next;
        last->next = NULL;
    }
    else{
        last = third = s;
        s = s->next;
        last->next = NULL;
    }
    while(f!= NULL && s!= NULL){
        if(f->data < s->data){
            last->next = f;
            last = f;
            f = f->next;
            last->next = NULL;
        }
        else{
            last->next = s;
            last = s;
            s = s->next;
            last->next = NULL;
        }
    }
if(f!= NULL){
    last->next = f;
}
else{
    last->next = s;
}
}
int isLoop(struct Node* f)
{
    struct Node *p, *q;
    p = q = f; 
    do{
        p = p->next;
        q = q->next;
        q = q ? q->next : q;

    } while (p && q && q!=p );
    return p == q ? 1 : 0;
}
void middleman(struct Node* p){
    struct Node* q = p; 
    while(q){
        q = q->next;
        if(q){
            q = q->next;
        }
        if(q){
            p = p->next;
        }
    }
    printf("Middle element data is %d ", p->data);
}

int main(){
    struct Node *t1, *t2; 
    int A[] = {1, 45, 55,56,68,7,8};
    createfromarray(A, 5);
    display(head);
    middleman(head);

    /*struct Node *k = rLinearSearch(head, 6)
    if(k){
        printf("\nKey found %d ", k->data);

    }
    else{
        printf("\nKey not found ");
    }
    
    if(isSorted(head)){
        printf("Linked list is sorted ");
    }
    else{
        printf("Linked list is not sorted");
    }*/

    

    
}
