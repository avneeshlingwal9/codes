//Bubble Sort 
#include <iostream>
using namespace std ;
void swp(int* a , int* b){
    int temp = *a ;
    *a = *b;
    *b = temp ;
}
void bsort(int arr[], int n){

    for(int i = 0 ; i < n-1 ; i++){
        bool swe = true  ;
        for(int j = 0 ; j< n-1-i; j++){
            if(arr[j] > arr[j+1]){
                swp(&arr[j],&arr[j+1]);
                swe = false ;

            }
        }
        if(swe){
            break ;
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
    bsort(arr,n);
    prarr(arr,n);

}