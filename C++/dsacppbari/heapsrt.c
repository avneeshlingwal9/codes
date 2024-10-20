#include <stdio.h>
#include <stdlib.h>
void swap(int* A ,int* B){
    int temp = *A;
    *A = *B;
    *B = temp;
}
void Insert(int A[], int i){
    int j = i, temp = 0 ;
    while(j > 1 && A[j] > A[j/2]){
        swap(&A[j],&A[j/2]);
        j = (j / 2 ); 
    }
}
void create(int A[], int n){
    for (int i = 2; i <= n; i++){
        Insert(A, i);
    }
}
void Delete(int A[] , int n ){
    int dl = A[1];
    A[1] = A[n];
    int i = 1, j = 2 * i;
    while(j< n-1){
        if(A[j+1]> A[j]){
            j = j + 1;
        }
        if(A[i] < A[j]){
            swap(&A[i], &A[j]);
        }
        i = j;
        j = 2 * i;
    }
    A[n] = dl;
}
void heapsort(int A[] , int n){
    for (int j = n; j > 1; j--){
        Delete(A, j);
    }
}



int main(){
    int A[] = {0, 40, 35, 30, 20, 2, 11, 9, 45};
    create(A,8);
    heapsort(A, 8);

    return 0;
}