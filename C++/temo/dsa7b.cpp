#include <iostream>
using namespace std ;
class Stackk{
    public :
    int size ;
    int* arr ;
    int top ;
    Stackk(int x){
        this->size = x;
        this->arr = new int[size];
        this->top = -1 ;
    }
    void push(int x){
        if(top== size-1){
            cout << "Overflow" << endl ;
        }
        else{
            arr[++top] = x ;
        }
    }
    int pop(){
        if(top==-1){
            cout << "Underflow " << endl ;
            return -1 ;
        }
        return arr[top--];
    }
    void sh(){
        for(int i = top ; i > -1 ; i--){
            cout << arr[i] << " " ;
        }
        cout << endl ;
    }
};
void numtobinary(int n ){
    Stackk k(20);
    int r = 0 ;
    while(n!=0){
        r = n%2 ;
        n = n/2 ;
        k.push(r);
        
    }
    k.sh();


}
int main(){
    numtobinary(8);

}