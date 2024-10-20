#include <iostream>
using namespace std ;
int linearSearch(int arr[] , int size ,int ele){
        if(size == 0){
            return -1 ;

        }
        else if(arr[size-1] == ele){
            return size-1 ;
        }
        return linearSearch(arr,size-1,ele);

    
}
int linerr(int arr[], int size , int pos , int ele){
    if(size <= pos){
        return -1 ; 
        
    }
    else if(arr[pos] == ele){
        return pos ;
    }
    return linerr(arr,size,pos+1,ele);
}
int main(){
    int n ,s ;
    cout << "Enter the number of elements you want to insert : - " << endl ;
    cin >> n ;
    int arr[n];
    cout << "Enter the elements in the array : - " << endl ;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];

    }
    cout << "Enter the element you want to search : - " << endl; 
    cin >> s ; 

    int p = linearSearch(arr,n,s);
    if(p!= -1){
        cout << p << " "; 
        cout << "Element exists ." << endl ;
    }
    else{
        cout << "Element not found" << endl; 
    }
    int k = linerr(arr,n,0,s);
    if(k!= -1){
        cout << k << " "; 
        cout << "Element exists ." << endl ;
    }
    else{
        cout << "Element not found" << endl; 
    }
}