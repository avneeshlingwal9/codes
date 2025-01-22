//Quick Sort 
#include <iostream>
using namespace std ;
void swp(int*a , int*b){
    int temp = *a ;
    *a = *b ;
    *b = temp ;
}
int part(int arr[],int st , int en){
    int pivo = arr[en];
    int r = st ; 
    for(int i = st ; i < en;i++){
        if(arr[i] < pivo){
            swp(&arr[i],&arr[r]);
            r++ ;


            
        }

    }
    swp(&arr[en],&arr[r]);
    return r ; 
    
}
void quicksrt(int arr[],int st , int en){
    if(st >= en){
        return ;
    }
    int p = part(arr,st,en);
    quicksrt(arr,st,p-1);
    quicksrt(arr,p+1,en);

}


void pr(int arr[], int n){
for(int i = 0 ; i < n ; i++){
    cout << arr[i] << " " ;

}
cout << endl ;
}
int main(){
    cout << "Quick Sort " << endl ;
    int n = 5;
    int arr[n] = {12,10,9,8,1};
    quicksrt(arr,0 ,n-1);
    pr(arr,n);
    

}
