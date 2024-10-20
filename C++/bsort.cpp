#include <iostream>
using namespace std ;
void swp(int *a , int* b){
    int temp = *a ;
    *a = *b ;
    *b = temp ;
}
void sh(int arr[], int size){
    for(int i = 0 ; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl ;
}
int main(){
    bool notswp = true; 
    int n = 8 ;
    int arr[n] = {26,13,23,12,7,38,42,45};

    for(int i = 0 ; i < n-1 ; i++){
        cout << "i " << i << endl ;
        sh(arr,n);
        for(int j = 0 ; j < n-1 ; j++){
            if(arr[j] > arr[j+1]){
                swp(&arr[j],&arr[j+1]);
                notswp = false ;

            }
        }
        
    }
}