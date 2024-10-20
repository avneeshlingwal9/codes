#include <iostream>
using namespace std ;
void swp(string* a , string* b){
    string temp = *a ;
    *a = *b ;
    *b = temp ;
}
//Using bubble sort
void sort(string arr[] , int l ){
    bool s = true ;
    for(int i = 0 ;i < l-1 ; i++){
        for(int j = 0 ; j < l-i-1 ; j++){
            if(arr[j] > arr[j+1]){
                swp(&arr[j],&arr[j+1]);
                s = false ;
            }

        }
        if(s){
            break ;
        }

    }
}
void display(string arr[] , int l){
    cout << "Elements of the array are: " << endl ;
    for(int i= 0 ; i < l ; i++){
        cout << arr[i] << " " ;
    }
    cout << endl ;
}
int main(){
    string arr[10];
    cout << "Enter 10 strings: " << endl ;
    for(int i = 0 ; i < 10 ; i ++ ){
        getline(cin,arr[i]);
    }
    display(arr,10);
    sort(arr,10);
    display(arr,10);


}