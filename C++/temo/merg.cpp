#include <iostream>
using namespace std ;
void merg(int arr[], int st , int mi , int en); 
void mergsrt(int arr[] , int st , int en){
    if(st >= en){
        return ; 
    }
int mid = (st + en)/2 ; 
mergsrt(arr, st , mid);
mergsrt(arr, mid+1 , en);
merg(arr, st , mid , en );




}
void merg(int arr[], int st , int mi , int en){
    
    int lb  = mi - st +1 ; 
    int rb  = en - mi ; 
    int k = st ;
    int *L = new int[lb] ;
    int *R = new int[rb] ;
    for(int i = 0 ; i < lb ; i++){
        L[i] = arr[st+i];
    }
    for(int j = 0 ; j < rb ; j ++){
        R[j] = arr[mi+1+j];
    }
    int i = 0 , j = 0  ;
        while(i < lb && j < rb ){
            if(L[i] < R[j]){
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while(i < lb){
            arr[k] = L[i];
            i++;
            k++;
        }
        while(j < rb){
            arr[k] = R[j];
            j++;
            k++;
        }
delete[] L;
delete[] R;

    
}
void prntar(int arr[], int n){
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " " ; 
    }
}
int main(){
    int n ; 
    cout << "Enter a number : - " << endl ; 
    cin >> n ; 
    int arr[n];
    cout << "Enter the elements in the array : - " << endl ; 
    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i];

    }
    prntar(arr,n);
    mergsrt(arr,0,n-1);
    prntar(arr,n);

}