
#include <stdio.h>
#include <stdlib.h>
void swap(int* A ,int* B){
    int temp = *A;
    *A = *B;
    *B = temp;
}
void bubblesrt(int A[], int n){
    int flag = 0;
    for (int i = 0; i < n - 1; i++){
        flag = 0 ; 
        for (int j = 0; j < n - 1 - i; j++){
            if(A[j] > A[j+1]){
                swap(&A[j + 1], &A[j]);
                flag = 1; 
            }
        }
        if(!flag){
            return;
        }
    }
}
void insertionsort(int A[], int n ){
    for (int i = 1; i < n; i++){
        int j = i - 1;
        int x = A[i];
        while(j > -1 && x < A[j] ){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x; 
    }
}
void selectionsort(int A[], int n){
    int k,j,i;
    for (i = 0; i < n - 1; i++){
        k = i;
        for (j = i; j < n; j++){

            if(A[j] < A[k]){
                k = j; 
            }
        }
        swap(&A[k], &A[i]);
    }

}
int partition(int A[], int l , int h){
    int pivot = A[l];
    int i = l, j = h; 
    do{
        do{
            i++;
        } while (A[i] <= pivot);
        do{
            j--;

        } while (A[j] > pivot);

        if(i < j){
            swap(&A[i], &A[j]);
        }
    } while (i < j);
    swap(&A[l], &A[j]);
    return j;
}
void quicksort(int A[], int l , int h ){
if(l < h ){
    int j = partition(A, l, h);
    quicksort(A, l, j);
    quicksort(A, j + 1, h);
}
}
void merge(int A[] , int l , int mid , int h){
    int i = l ;
    int j = mid + 1; 
    int k = l ;
    int B[100];
    while( i <= mid && j <=h){
        if(A[i] < A[j]){
            B[k++] = A[i++];
        }
        else{
            B[k++] = A[j++];
        }
    }
    for (; i <= mid; i++){
        B[k++] = A[i];
    }
    for (; j <= h; j++){
        B[k++] = A[j];
    }
    for ( i = l; i <=h ; i++){
        A[i] = B[i];
    }
}
void IMergesort(int A[], int n){
    int p, i, l, mid, h;
    for (p = 2; p <= n; p = 2*p){
        for (i = 0; i + p - 1 < n; i = i+p){
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(A, l, mid, h);
        }
        if(n-i > p/2){
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(A, l, mid, n - 1);
        }
    }
    if(p/2 < n){
        merge(A, 0, (p / 2)-1 , n-1 );
    }
}
void RMergeSort(int A[] , int l , int h){
    if(l< h){
        int mid = (l + h) / 2;
        RMergeSort(A, 0, mid);
        RMergeSort(A, mid + 1, h);
        merge(A, l, mid, h);
    }
}
int findmax(int A[] , int n){
    int ma = INT_MIN;
    for (int i = 0; i < n; i++){
        if(A[i] > ma ){
            ma = A[i];
        }
    }
    return ma; 
}
void CountSort(int A[] , int n){
    int m = findmax(A, n);
    int *C = (int *)malloc(sizeof(int) * (m + 1));
    int i, j;
    for (i = 0; i < m+1; i++)
    {
        C[i] = 0;
    }
    for (i = 0; i < n; i++){
        C[A[i]]++;
    }
    j = 0, i = 0;
    while(j < n){
        if(C[i]> 0){
            A[j++] = i;
            C[i]--;
        }
        else{
            i++;
        }


    }
}

int main(){
    int A[] = {98,98,98,98,98, 4, 65, 3, 21, 879, 5};
    CountSort(A,11);

    }