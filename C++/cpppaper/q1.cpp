#include <iostream>
using namespace std ;
//Function for swapping 
void swp(int* a , int* b){
    int temp = *a ;
    *a = *b;
    *b = temp; 
}
//Separating the odd and even elements 
void seperate(int arr[], int l){
    int pivot = 0 ;

    for(int i = 0 ; i < l ; i++ ){
        if(arr[i]%2 == 0) {
            swp(&arr[i],&arr[pivot]);
            pivot++ ;
        }

        }
        

    }
void display(int arr[] , int l ){
    cout << "Elements of the array are: "<< endl ;
    for(int i =0 ; i < l ; i++){
        cout << arr[i] << " " ; 
    }
    cout << endl ;
}

int main(){
    int n ; 
    cout << "Enter the strength of the students: " << endl ;
    cin >> n ; 
    int arr[n];
    cout << "Enter the roll no. of students: " << endl ;
    for(int i = 0 ; i < n; i++){
        cin >> arr[i];
    }
    cin.ignore();
    display(arr,n);
    seperate(arr,n);
    display(arr,n);



}