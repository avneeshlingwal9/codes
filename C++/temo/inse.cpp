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
    for(int i =0 ; i < n-1; i ++){
        if(arr[i] > arr[i+1]){
            swp(&arr[i],&arr[i+1]);
            for(int j = i-1 ; j >0 ; j-- ){
                if(arr[j]> arr[j+1]){
                    swp(&arr[j],&arr[j+1]);

                }

            }
        }

    }
    












    for( int i : arr){
        cout << i << " " ; 
    }


    
    
    }