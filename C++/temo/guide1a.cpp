//Insertion Sort 

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

void pr(int arr[], int n){
for(int i = 0 ; i < n ; i++){
    cout << arr[i] << " " ;

}
cout << endl ;
}
int main(){
    cout << "Insertion Sort" << endl; 
    int n = 5;
    int arr[n] = {12,10,9,8,1};
    insort(arr,n);
    pr(arr,n);

}
