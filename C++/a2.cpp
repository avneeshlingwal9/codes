#include <iostream>
using namespace std ;
void swp(int *a , int* b){
    int temp = *a ; 
    *a = *b ;
    *b = temp ;
}
void bsort(int arr[] , int n ){
    bool swapd = false ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j <n-1 ; j ++){
            if(arr[j] > arr[j+1]){
                swp(&arr[j],&arr[j+1]);
                swapd = true ;
            }

        }
        if(!swapd){
            break ;
        
        }
    }
    

}
bool lsearch(int arr[] , int n, int find){
    for (int i = 0 ; i< n ; i++ ){
        if(arr[i]== find){
            return true ;
        }
    }
    return false ;

}

int main(){
    int arr[10] ;
    int f ;
    cout << "Enter the elements of the array : - " << endl ;
    for(int i = 0 ; i < 10 ; i++){
        cin >> arr[i];

    }
    bsort(arr,10);
    for(const int l : arr){
        cout << l << " " ; 
    }
    cout << "Enter the element you want to search for : - " << endl ;
    cin >> f ;
    if(lsearch(arr, 10 , f)){
        cout << "Element found " << endl ;
    }
    else {
        cout << "Element is not contained " << endl ;
    }
    

}