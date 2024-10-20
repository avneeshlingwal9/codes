#include <iostream>
using namespace std ;
void swp(int *a , int *b){
    int temp = *a ; 
    *a = *b;
    *b = temp ;
} 


int prtion(int arr[], int low , int high){
    int great = low;
    int pivot = arr[high];
    for(int j = low ; j < high; j++){
        if(arr[j]< pivot){
            swp(&arr[j],&arr[great]);
            great++;
        }
        

        

    }
    swp(&arr[great],&arr[high]);
    return great ; 


}
void qucksrt(int arr[] , int low , int high){
    if(low < high){
    int p = prtion(arr,low,high);
    qucksrt(arr,low,p-1);
    qucksrt(arr,p+1,high);
}}
void prar(int arr[] , int n ){
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " " ; 
    }
    cout << endl ; 
}


int main(){
    int arr[] = {5,4,3,2,1};
    int n = (sizeof(arr)/sizeof(arr[0]));
    cout << n << "" << endl ; 

    prar(arr,5);
    qucksrt(arr,0,4);
    prar(arr,5);


}