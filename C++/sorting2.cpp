//Bubble Sort 
#include <iostream>
using namespace std ;
void swp(int* a , int* b){
    int temp = *a ;
    *a = *b;
    *b = temp ;
}
void insort(int arr[], int n){
    for(int i = 0 ; i < n-1 ; i++){
        int j = i ;
        while(arr[j+1] < arr[j]){
            swp(&arr[j+1],&arr[j]);
            j--;
        }
    }
}
void prarr(int arr[], int n){
    for(int i =0 ;i < n ; i++){
        cout<< arr[i] << " " ;
    }
    cout << endl ;
}
int main(){
    int n = 4 ;
    int arr[n] = {4,3,2,1};
    prarr(arr,n);
    insort(arr,n);
    prarr(arr,n);

}