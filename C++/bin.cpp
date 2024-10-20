#include <iostream>
using namespace std ;
void swp ( int* a , int* b){
    int tem = *a ;
    *a = *b ;
    *b = tem ; 
}
void insrt ( int arr[] , int n){
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
}
void binarysearch(int arr[] ,int b ,  int n , int s){
        int m = (b+n)/2;
        if(n>=b){
        if(arr[m] < s){
            binarysearch( arr , b,m ,  s);
        }
        else if( arr[m] > s){
            binarysearch( arr, m , n , s );
        }
        else if (arr[m]==s){
            cout << "Element has been found. " << endl ;
            }
        else {
            cout << "Element does not exist in the array ." << endl ; 
        }
        }}
        

    
    












    


    
    
    
int main(){
    int n ; 
    cout << "Enter the number of elements you want to enter : - " << endl ; 
    cin >> n ;
    int arr[n];
    cout << "Enter the elements in array : - " << endl ; 
    for(int i =0 ; i < n ; i++){
        cin >> arr[i];
    }
    insrt(arr , n);
    int s ; 
    cout << "Enter the element you want to search : - " << endl ;
    cin >> s ;
    binarysearch(arr,0,n,s);

}