#include <iostream>
using namespace std ;
void sp(int* a , int* b){
    int temp = *a ; 
    *a = *b ; 
    *b = temp ;
}
int main(){
    int n ; 
    cout << "Enter the number of elements for array : - " << endl ; 
    cin >> n ;
    int arr[n] ;
    cout <<"Enter the elements : - " << endl ; 
    bool sping ; 

    for ( int i = 0 ; i < n ; i ++ ){
        cin >> arr[i];
    }
    for (int i = 0 ; i < n-1 ; i ++){
        sping = false ;
        for (int j = 0 ; j < n-1-i ; j++){
            if ( arr[j] > arr[j+1]){
                sp(&arr[j], &arr[j+1]);
                sping = true ;            
        }}
        if (sping == false){
            break;
        }
    }
    for ( const int &i :arr ){
        cout << i << " " ; 

    }
    
}