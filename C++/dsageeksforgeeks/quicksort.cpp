#include <iostream>
using namespace std;
void display(int a[] , int n){
    for (int i = 0; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << endl; 
}
void adswap(int*a , int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int *arr, int l , int h){

    int pivot = arr[l];
    int i = l, j = h;
    cout << " In iteration ";
    display(arr,7);
    while(i<j){
    while(arr[i] <= pivot){
        i++;
    }

    while(arr[j] > pivot){
        j--;
    }
    if(i < j){    
        adswap(&arr[i], &arr[j]);
        }
    } 
    adswap(&arr[l],&arr[j]);
    return j;
}
void quicksort(int *a , int l , int h){
    if(l < h){
        int part = partition(a,l,h);
        quicksort(a, l, part-1 );
        quicksort(a, part + 1, h);
    }
}

int main(){
    int a[] = {5,32,35,56,6,3,23,4};
    quicksort(a, 0, 7);

    }   