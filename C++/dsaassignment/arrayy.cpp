#include <iostream>
using namespace std;
/*Creating an structure array contain*/
struct Array{
    int *data;
    int size;
};
void swap(int * a , int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int A[], int low , int high){
    int piv = A[low];
    int i = low;
    int j = high;
    while(i < j){
        while(A[i] <= piv && i < high){
            i++;
        }
        while(A[j] > piv && j > low){
            j--;
        }
        if(i < j){
            swap(&A[i], &A[j]);
        }

    }
    swap(&A[low], &A[j]);
    return j; 
}
//Sorting the elements using quicksort 
void quickSort(int A[],int begin , int end){
    if(begin < end){
        int pivot = partition(A, begin, end);
        quickSort(A, begin, pivot - 1);
        quickSort(A, pivot + 1, end);
    }
}
/* Function to find intersection of two arrays */
int* intersection_arrays(int A[] , int m , int B[] , int n){
    int size = min(m,n); 
    // As the maximum size of the intersection of two arrays will be equal to the size of the smallest array.
    int *ans = new int[size];
    quickSort(A, 0, m - 1);
    quickSort(B, 0, n - 1);
    /* 
    Sorting both the arrays so that we can find intersecting pairs in one traversal 
    */
    int indA = 0; // To keep track of indices of A
    int indB = 0 ;  // To keep track indices of B
    int indans = 0; // To keep track of indices of ans
    while(indA < m && indB < n){
        if(A[indA] < B[indB]){
            indA++;
        }
        else if(A[indA] > B[indB]){
            indB++;
        }
        else{
            ans[indans++] = A[indA++];
            indB++;
        }
    } 

    return ans;
}
void display(int A[] , int n ){
    for (int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}
int main(){
    int A[] = {3, 9, 9, 9, 9};
    int B[] = {1, 2, 3, 5, 6, 7};

    
}
