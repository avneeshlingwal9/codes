#include <iostream>
using namespace std ; 
void swp(int*a , int*b){
    int temp = *a ;
    *a = *b ;
    *b = temp ;
}
void insort(int arr[], int l){
    for(int i = 0 ; i < l-1 ;i++){
        int j = i ;
        while(j>=0 && arr[j+1] < arr[j]){
            swp(&arr[j+1],&arr[j]);
            j-- ;

        }
    }
}
int binarysearch(int arr[], int start , int end ,int ele){
    
    if(start>=end){
        return -1 ;
    }
    int mid = (start+end)/2 ;
    if(arr[mid] == ele){
        return mid ;

    }
    else if(arr[mid] > ele){
        return binarysearch(arr,start,mid,ele);
    }
    else if(arr[mid] < ele){
        return binarysearch(arr,mid+1,end,ele);
    }

    

}
void prntarr(int arr[] , int n){
    for(int i = 0; i < n ; i++){
        cout << arr[i] << " " ;
    }
    cout << endl; 
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
    prntarr(arr,n);
    insort(arr,n);
    cout <<"Sorted array :"  << endl; 
    prntarr(arr,n);
    int f ;
    cout << "Enter the element you want to search in the array: " << endl;
    cin >> f ;
    if(binarysearch(arr,0 ,n,f)==-1){
        cout << "Element not found " << endl ;
    }
    else{
        cout << "Element found at index " << binarysearch(arr,0,n,f) << endl ; 
    }



}