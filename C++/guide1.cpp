#include <iostream>
//BUBBLE SORT 
using namespace std ;
void swp(int*a , int*b){
    int temp = *a ;
    *a = *b ;
    *b = temp ;
}
void bsort(int arr[], int n ){
    for(int i = 0 ; i < n-1; i++){
        bool swapp = false ;
        for(int j=0; j < n-1 ; j++){
            if(arr[j]> arr[j+1]){
                swp(&arr[j],&arr[j+1]);
                swapp = true ;
            }
        }
        if(!swapp ){
            break ; 
        }
    }
}
void pr(int arr[], int n){
for(int i = 0 ; i < n ; i++){
    cout << arr[i] << " " ;

}
cout << endl ;
}
int main(){
    int n = 10 ;
    cout << "Bubble Sort" << endl; 
    int arr[n] = {9,8,7,6,5,4,3,2,1,14};
    bsort(arr,n);
    pr(arr,n);

}