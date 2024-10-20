#include <iostream>
using namespace std;
class Tridiagonalmatrix{
    public:
    int size ; 
    int* arr ; 
    Tridiagonalmatrix(int s){
        this->size = s ;
        this->arr = new int[3*size-2];
    }
    void setelement(int i , int j ,int x){
        if(i == j){
            arr[i] = x ;
        }
        else if(i == j+1){
            arr[size+i] = x ; 
        }
        else if(i== j-1){
            arr[2*size+1 - i] = x;
        }
    }
    int retreive(int i , int j){
        if(i == j){
            return arr[i];
        }
        else if( i == j+1){
            return arr[size+i];
        }
        else if(i ==j-1){
            return arr[2*size+1 - i];
        }
        else{
            return 0 ; 
        }
    }
};