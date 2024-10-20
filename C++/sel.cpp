#include <iostream>
using namespace std ;
void swp ( int* a , int* b){
    int tem = *a ;
    *a = *b ;
    *b = tem ; 
}
int main(){
    int n ; 
    cout << "Enter the number of elements you want to enter : - " << endl ; 
    cin >> n ;
    int arr[n];
    cout << "Enter the elements in array : - " << endl ; 
    for(int i =0 ; i < n ; i++){
        cin >> arr[i];
    }
    for ( int i = 0 ; i < n-1 ; i ++){
        int s = i ; 
        for ( int j = i+1 ; j < n ; j++ ){
            if(arr[j]<arr[s]){
                s = j ;
            }
        }
        if(s!= i){
            swp(&arr[i],&arr[s]);
        }
    }
    for( int i : arr){
        cout << i << " " ; 
    }


    
    
    }