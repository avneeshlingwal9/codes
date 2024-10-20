#include <stdlib.h>
#include <stdio.h>
struct Element{
    int i;
    int j;
    int x;
};
struct Sparse{
    int n;
    int m;
    int num;
    struct Element *el;
};
void create(struct Sparse *s){
    printf("Enter dimensions: ");
    scanf("%d%d", &s->m, &s->n);
    printf("Enter the number of non zero elements:");
    scanf("%d", &s->num);
    s->el = (struct Element *)malloc(sizeof(struct Element) * s->num);
    printf("Enter the coordinates and element: ");
    for (int i = 0; i < s->num; i++){
        scanf("%d%d%d",&s->el[i].i , &s->el[i].j,&s->el[i].x);

    }
}
void display(struct Sparse s){
    int i, j, k = 0;
    for (i = 0; i < s.m;i++){
        for (j = 0; j < s.n; j++){
            if(i == s.el[k].i && j == s.el[k].j){
                printf("%d ", s.el[k++].x);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}
struct Sparse* add(struct Sparse* s1 , struct Sparse* s2)

{
    struct Sparse *sum; 
    if(s1->m == s2->m && s1->n == s2->n){
        int i = 0, j = 0, k = 0;
        sum = (struct Sparse *)malloc(sizeof(struct Sparse));
        sum->m = s1->m;
        sum->n = s1->n;
        sum->el = (struct Element *)malloc(sizeof(struct Element) * (s1->num + s2->num));
        while(i < s1->num && j < s2->num){
            if(s1->el[i].i < s2->el[j].i){
                sum->el[k++] = s1->el[i++];
            }
            else if(s1->el[i].i > s2->el[j].i){
                sum->el[k++] = s2->el[j++];
            }
            else{
                if(s1->el[i].j < s2->el[j].j){
                    sum->el[k++] = s1->el[i++];
                }
                else if(s1->el[i].j > s2->el[j].j){
                    sum->el[k++] = s2->el[j++];
                }
                else{
                    sum->el[k] = s1->el[i++];
                    sum->el[k++].x += s2->el[j++].x;
                }
            }
        }
        for (; i < s1->num; i++){
            sum->el[k++] = s1->el[i];
        }
        for (; j < s2->num;j++){
            sum->el[k++] = s2->el[j];
        }
            sum->num = k;
        return sum;
    }
    printf("Matrices cannot be added");
    exit(0);
    return NULL;
}   
     

int main(){
    struct Sparse s;
    struct Sparse s2;
    struct Sparse *s3;
    

    create(&s);
    display(s);
    create(&s2);
    printf("\n");
    display(s2);
    printf("\n");
    s3 = add(&s,&s2);
    display(*s3);
    free(s.el);
    free(s2.el);
    free(s3->el);
    free(s3);
        
}