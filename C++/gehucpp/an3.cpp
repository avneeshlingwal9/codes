#include <iostream>
using namespace std ;


void print1d(int* arr , int size){
    for(int i = 0 ; i < size ; i++){
        cout << *(arr+i) << " ";
    }
    cout << endl ; 

}
int sum2darray(int* ptr , int row , int col ){
    int smm = 0 ;
    for(int i = 0 ; i < row*col; i++){
        smm+=*(ptr+i);
    }
    return smm ; 
}
int main(){
    cout << "Name :- Anushka Negi " << endl ;
    cout << "Section:- G1 " << endl; 
    cout << "Roll No. :- 11 " << endl ; 
    int size1d , sizerow , sizecol ; 
    cout << "Enter size of 1-d array : - " << endl ;
    cin >> size1d ; 
    int arr1d[size1d];
    cout << "Enter elements in the array : - " << endl ; 
    for(int i = 0; i < size1d; i++){
        cin >> arr1d[i] ;

    }
    int* p = arr1d;
    print1d(p,size1d);
    cout << "Enter the number of rows in the 2-d array :- " << endl ;
    cin >> sizerow ;
    cout << "Enter the number of columns in the 2-d array : - " << endl ; 
    cin >> sizecol ;
    int arr2d[sizerow][sizecol];
    cout << "Enter the elements in the array : - " << endl ; 
    for(int i = 0 ; i < sizerow ; i++){
        for(int j = 0 ; j < sizecol ; j++){
            cin >> arr2d[i][j] ;
        }
    }
    int* ptr2d = &arr2d[0][0] ;
    cout << "Sum of the 2-d array : - " << sum2darray( ptr2d , sizerow , sizecol) << endl ; 

    
}