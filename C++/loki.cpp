#include <iostream>
using namespace std ;
void swp(int* a , int* b){
    int temp = *a ;
    *a = *b ;
    *b = temp ;
}
void insertsort(int arr[], int n){
    for(int i = 0 ; i < n-1 ; i++){
        int j =  i ;
        while( j >= 0 && arr[j+1] < arr[j]){
            swp(&arr[j],&arr[j+1]);
            j-- ;

        }
    }
}