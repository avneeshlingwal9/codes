//Selection Sort
#include <iostream>
using namespace std ;
void swp(int* a , int* b){
    int temp = *a ;
    *a = *b;
    *b = temp ;
}
int min(int arr[], int st , int en){
    int min = st ;
    int el = arr[st];
    for(int i = st ; i < en ; i++){
        if(arr[i] < el){
            el = arr[i];
            min = i ;


        }
    }
    return min ;
}
void selsort(int arr[], int n){
    for(int i =0 ; i < n ; i++){
        int m = min(arr,i,n);
        swp(&arr[m],&arr[i]);
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
    selsort(arr,n);
    prarr(arr,n);

}