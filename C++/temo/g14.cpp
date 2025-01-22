#include <iostream>
using namespace std ;
class mtrix {
    public :
    int arr1[20][20],arr2[20][20],arr3[20][20],r,c,msm[20][20],dif[20][20],tp[20][20];
    mtrix(){
        cout <<"Enter the number of rows and columns for the matrix : - " << endl ;
        cin >> r >> c ;  
    }
    void sm(){
        cout <<"Enter the elements of the first array : - " << endl ; 
        for ( int i = 0 ; i < r ;i++){
            for ( int j = 0 ; j < c ; j++){
                cin >> arr1[i][j];
            }

        }
        cout <<"Enter the elements of the second  array : - " << endl ; 
        for ( int i = 0 ; i < r ;i++){
            for ( int j = 0 ; j < c ; j++){
                cin >> arr2[i][j];
                msm[i][j]= arr1[i][j]+arr2[i][j];
            }}
        cout << "The sum of the matrices is : - " << endl ; 
        for ( int i = 0 ; i < r ; i++){
            for ( int j = 0 ; j < c ; j++){
                cout << msm[i][j] << " " ;
            }
            cout << endl ;
        }
        cout << endl ;

        
    }
        void mdiff(){
        cout <<"Enter the elements of the first array : - " << endl ; 
        for ( int i = 0 ; i < r ;i++){
            for ( int j = 0 ; j < c ; j++){
                cin >> arr1[i][j];
            }

        }
        cout <<"Enter the elements of the second  array : - " << endl ; 
        for ( int i = 0 ; i < r ;i++){
            for ( int j = 0 ; j < c ; j++){
                cin >> arr2[i][j];
                dif[i][j]= arr1[i][j]-arr2[i][j];
            }}
        cout << "The difference of the matrices is : - " << endl ; 
        for ( int i = 0 ; i < r ; i++){
            for ( int j = 0 ; j < c ; j++){
                cout << dif[i][j] << " " ;
            }
            cout << endl ;
        }
        cout << endl ;

        
    }
    void transp(){
        cout << "Enter the matrix to be transposed : - "  << endl ; 
        for ( int i = 0 ; i < r ; i ++){
            for ( int j = 0 ; j < c ; j++){
                cin >> arr3[i][j];
                tp[j][i] = arr3[i][j];
            }
        }
        cout << "The elements of the transposed matrix is : - " << endl ; 
        for ( int i =0 ; i < r ; i++){
            for ( int j =0 ; j < c ; j++){
                cout << tp[i][j] <<" " ;
            }
            cout << endl ;
        }
        cout << endl ;
    }



};
int main(){
    mtrix m1 ;
    string inp ; 
    cout << "Enter the operation you want to perform on matrix " ;
    cout << " /'ADD'/ for addition  /'DIFF'/ for difference and /'TP'/ for transpose " << endl ;
    cin >> inp ; 
    if (inp == "ADD"){
        m1.sm();
    } 
    else if ( inp == "DIFF"){
        m1.mdiff();
    }
    else if ( inp == "TP"){
        m1.transp();
    }
    else {
        cout << "Invalid input" << endl ;
}}
