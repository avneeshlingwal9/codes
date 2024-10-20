//Merge Sort 
#include <iostream>
using namespace std ;
void merg(int arr[],int sta , int mid , int en);
void mergesrt(int arr[], int sta , int end){
    int mid = (sta+ end)/2 ;
    if(sta >= end){
        return ;
    }
    mergesrt(arr,sta,mid);
    mergesrt(arr,mid+1,end);
    merg(arr,sta,mid,end);
}
void merg(int arr[],int sta , int mid , int en){
    if(sta >=en){
        return ;
    }
    int l = mid-sta +1 ;
    int r = en - mid ; 
    int s = sta ;
    int lef[l];
    int rig[r];
    for(int i = 0 ; i < l ;i++){
        lef[i] = arr[sta+i];

    }
    for(int j = 0 ; j < r ; j++){
        rig[j] = arr[mid+1+j];
    }
    int li = 0 ; 
    int ri = 0 ; 
    while(li < l && ri < r){
        if(lef[li] < rig[ri]){
            arr[s] = lef[li++];

        }
        else{
            arr[s] = rig[ri++];

        }
        s++;
    }
    while(li < l){
        arr[s++] = lef[li++];
    }
    while(ri < r){
        arr[s++] = rig[ri++];
    }



}


void pr(int arr[], int n){
for(int i = 0 ; i < n ; i++){
    cout << arr[i] << " " ;

}
cout << endl ;
}
int main(){
    cout << "Merge Sort " << endl; 
    int n = 5;
    int arr[n] = {12,10,9,8,1};
    mergesrt(arr,0,n-1);
    pr(arr,n);

}
