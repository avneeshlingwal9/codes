#include <iostream>
using namespace std ;
int bnarysrh(int arr[] , int sta , int en , int fnd ){
    if(sta <= en){
    int mid = (sta + en)/2 ; 
    if(arr[mid]== fnd){
        return mid ; 
    }
    else if (arr[mid] > fnd){
    return bnarysrh(arr , sta , mid-1 ,fnd);}
    
    else{
    return  bnarysrh(arr,mid+1,en,fnd);
    }}
    return -1 ; 
}
int main(){
    int n , s ; 
    cout << "Enter the number of elements you want to insert : - " << endl ; 
    cin >> n ; 
    int arr[n];
    cout << "Enter the elements of the array : - " << endl ; 
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    cout << "Enter the element you want to search in the array : - " << endl ; 
    cin >> s ; 
    int reslt = bnarysrh(arr,0,n-1,s);
    if(reslt == -1){
        cout << "Element does not exist in the array ." << endl ; 

    }
    else {
        cout << "Element exist in the array at index " << reslt << endl ; 

    }
}