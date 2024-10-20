//Selection Sort
#include <iostream>
using namespace std ;
void swp(int*a , int*b){
    int temp = *a ;
    *a = *b ;
    *b = temp ;
}
int findmin(int arr[],int sta , int end){
    int min = arr[sta];
    int k = sta ; 
    for(int i =sta; i < end ; i++){
        if( arr[i] < min){
            min = arr[i];
            k = i ;

        }
    }
    return k ; 
}
void selsort(int arr[], int l ){
    for(int i = 0 ; i < l ; i++){
        int minindex = findmin(arr,i,l);
        swp(&arr[i],&arr[minindex]);
    }
}
void pr(int arr[], int n){
for(int i = 0 ; i < n ; i++){
    cout << arr[i] << " " ;

}
cout << endl ;
}
int main(){
    cout << "Selection Sort" << endl; 
    int n = 5;
    int arr[n] = {12,10,9,8,1};
    cout << findmin(arr,0,n) << endl ; 
    selsort(arr,n);
    pr(arr,n);
    

}
