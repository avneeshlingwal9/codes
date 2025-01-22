#include <iostream>
using namespace std ;
class diagonalMatrix{
    public :
    int size ;
    int* arr ;
    diagonalMatrix(int s){
        this->size = s ;
        this->arr = new int[size];
    }
    void store(int x , int y , int elemen){
        if(x==y){
            arr[x-1] = elemen ;
        }

    }
    int retrieve(int x , int y){
        if(x != y){
            return 0 ;
        }
        return arr[x-1];

    }
    void sh(){
        for(int i = 0 ; i < size ; i++){
            cout << arr[i] << " " ;
        }
        cout << endl ; 
    }

};
int main(){
    int n ;
    
    diagonalMatrix d(5);
    d.store(1,1,5);
    d.store(2,2,8);
    d.store(3,3,9);
    d.store(4,4,14);
    d.store(5,5,70);
    d.sh();

}