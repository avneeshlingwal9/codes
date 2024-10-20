#include <stdlib.h>
#include <stdio.h>

struct upperTriangular{
    int n;
    int *A;
};
void setRowMajor(struct upperTriangular *u , int i , int j , int el){
    if(i<=j){
        u->A[(i - 1) * u->n - (i - 1) * (i - 2) / 2 + j - i] = el;
    }
}
void setColumnMajor(struct upperTriangular *u , int i , int j , int el){
    if(i<=j){
        u->A[j * (j - 1) / 2 + i - 1] = el;
    }
}
int getRowMajor(struct upperTriangular u , int i, int j ){
    if(i<=j){
        return u.A[(i - 1) * u.n - (i - 1) * (i - 2) / 2 + j - i];
    }
    return 0; 
}
int getColumnMajor(struct upperTriangular u , int i , int j){
    if(i<=j){
        return u.A[j * (j - 1) / 2 + i - 1];
    }
    return 0; 
}
void displayRow(struct upperTriangular u){
    for (int i = 1; i <= u.n; i++)
    {
        for (int j = 1; j <= u.n; j++){
            if(i<=j){
                printf("%d ", u.A[(i - 1) * u.n - (i - 1) * (i - 2) / 2 + j - i]);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}
void displayColumn(struct upperTriangular u ){
    for (int i = 1; i <= u.n; i++){
        for (int j = 1; j <= u.n; j++){
            if(i<=j)
            {
                printf("%d ", u.A[j * (j - 1) / 2 + i - 1]);}

      else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}
int main(){
    struct upperTriangular u;
    int i, j, x;
    printf("Enter dimensions: ");
    scanf("%d", &u.n);
    u.A = (int*)malloc(sizeof(int)*u.n*(u.n+1)/2) ;
    printf("Enter elements:");
    for (i = 1; i <= u.n; i++){
        for (j = 1; j <= u.n;j++){
            scanf("%d", &x);
            setRowMajor(&u, i, j, x);
        }
    }
    displayRow(u);
}