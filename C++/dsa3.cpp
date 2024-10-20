#include <iostream>
using namespace std ;
void merg(int arr[], int start, int mid , int end);
void mergesrt(int arr[] , int start , int end){
    if(start>= end){
        return ;
    }
    int mid = (start+end) /2 ; 
    mergesrt(arr,start,mid);
    mergesrt(arr,mid+1,end);
    merg(arr,start,mid,end);
    
}
void merg(int arr[], int start, int mid , int end){
    int j  = mid-start+1 ;
    int k = end - mid ;
    int templeft[j] ;
    int tempright[k];
    int s = start; 
    for(int i = start ,l = 0 ; i < mid+1 ; i++,l++){
        templeft[l] = arr[i];
    }
    for(int i = mid+1 ,l =0 ; i < end ; i++ , l++ ){
        tempright[l] = arr[i];
    }
    int m = 0 , n = 0 ;
    while((m!= j ) &&(n!= k) ){
        if(templeft[m] > tempright[n]){
            arr[s] = tempright[n];
            n++;
            s++;
        }
        else{
            arr[s] = templeft[m];
            m++;
            s++;
        }
    }
    while (m!= j)
    {
        arr[s] = templeft[m];
        s++;
        m++;

    
    }
    while(n!= k){
        arr[s] = tempright[n];
        n++;
        s++;
    }
    

}
void sh(int arr[] , int size){
    for(int i = 0 ; i < size ; i++){
        cout << arr[i] << " " ;
    }
    cout << endl ;
    
}

int main()
{
    int arr[6] = {9,8,7,5,6,3};
    sh(arr,6);
    mergesrt(arr,0,5);
    sh(arr,6);

}