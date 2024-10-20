// Linear Search in Array 
#include <iostream>
using namespace std ;
int linearsearch(int arr[], int len , int ele){
    int r = -1;


    for(int i =0 ; i < len ; i++){
        if(arr[i]== ele){
            r = i ; 
            return r ;
        }}
        
            return r ;
        



    }


int main(){
    int n ; 
    cout << "Enter the number of elements you want to insert : " << endl ;
    cin >> n ;
    cout << "Enter the elements in the array: " << endl ;
    int arr[n];
    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i] ;

    }
    int f ;
    cout << "Enter the element you want to search in the array: " << endl;
    cin >> f ;
    if(linearsearch(arr,n,f)==-1){
        cout << "Element not found " << endl ;
    }
    else{
        cout << "Element found at index " << linearsearch(arr,n,f) << endl ; 
    }

}