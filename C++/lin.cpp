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
    int s ; 
    cout << "Enter the element you want to search : - "<< endl  ;
    cin >> s ; 
    bool found = false ;
    for (int i = 0 ; i < n ; i ++){
        if(arr[i]== s){
            found = true ;
            break ; 

        }
    }


    if(found ){
        cout << "Element has been found " << endl  ;
    }
    else {
        cout << "Element is not contained in the array ." << endl ;
    }    
    }