#include <math.h>
#include <stdlib.h>
#include <stdio.h>
struct Term{
    int coef;
    int exp;
};
struct Poly{
    int n;
    struct Term *t;
};
void create(struct Poly *p){
    printf("Enter the number of elements: ");
    scanf("%d", &p->n);
    p->t = (struct Term *)malloc(sizeof(struct Term) * p->n);
    printf("Enter the terms: \n");
    for (int i = 0; i < p->n;i++){
        scanf("%d%d", &p->t[i].coef,&p->t[i].exp);
    }
}
int eval(struct Poly *p , int x){
    int sum = 0;
    for (int i = 0; i < p->n; i++){
        sum += p->t[i].coef * pow(x, p->t[i].exp);
    }
    return sum;
}
void display(struct Poly p){
    for (int i = 0; i < p.n; i++){
        printf("%d*x^%d  + ", p.t[i].coef, p.t[i].exp);
    }
    printf("\n");
}
struct Poly* add(struct Poly *p1 , struct Poly *p2 ){
    struct Poly *p = (struct Poly *)malloc(sizeof(struct Poly));
    p->t = (struct Term *)malloc(sizeof(struct Term) * (p1->n + p2->n));
    int i = 0, j = 0, k = 0;
    while (i < p1->n && j < p2->n){
        if(p1->t[i].exp < p2->t[j].exp){
            p->t[k++] = p2->t[j++];
        }
        else if(p1->t[i].exp > p2->t[j].exp){
            p->t[k++] = p1->t[i++];
        }
        else{
            p->t[k] = p1->t[i++];
            p->t[k++].coef += p2->t[j++].coef;
        }
    }
    for (; i < p1->n; i++){
        p->t[k++] = p1->t[i];
    }
    for (; j < p2->n; j++){
        p->t[k++] = p2->t[j];
    }
    p->n = k;
    return p;
}
int main(){
    struct Poly p,p1,*p2;
    create(&p);
    display(p);
    create(&p1);
    display(p1);
    p2 = add(&p, &p1);
    display(*p2);

    free(p.t);
    free(p1.t);
    free(p2->t);
    free(p2);
}