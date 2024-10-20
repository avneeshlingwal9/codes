#include <stdlib.h>
#include <stdio.h>
struct diagonalL{
    int *A;
    int n;
};
void set(struct diagonalL *m , int i , int j , int ele){
    if(i>=j){
        m->A[m->n*(j-1) - (j-1)*(j-2)/2 + i-j] = ele;
    }

}
int get(struct diagonalL m , int i , int j){
    if(i>=j){
        return m.A[m.n*(j-1) - (j-1)*(j-2)/2 + i-j];
    }
    return 0; 
}
void display(struct diagonalL m){
    for (int i = 1; i <= m.n; i++){
        for (int j = 1; j <= m.n; j++){
            if(i>=j){
                printf("%d ", m.A[m.n*(j-1) - (j-1)*(j-2)/2 + i-j]);
            }
            else{
                printf("%d ", 0);
            }
        }
        printf("\n");
    }
}

int main(){
    int i, j, x;
    struct diagonalL l;
    printf("Enter the number of elements you want to insert: ");
    scanf("%d", &l.n);
    l.A = (int *)malloc(sizeof(int) * (i) * (i - 1) / 2);
    printf("Enter the elements you want to insert: ");
    for (i = 1; i <= l.n; i++){
        for (j = 1; j <= l.n;j++){
            scanf("%d", &x);
            set(&l, i, j, x);
        }
    }

    display(l);
}