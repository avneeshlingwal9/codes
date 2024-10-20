#include <iostream>
using namespace std ;
int fnct(int a , int b){
    if(a <b){
        return 0 ;
    }
    return fnct(a-b,b)+1 ;

}
int main(){
    cout << fnct(2,3) << endl ;
    cout << fnct(14,3) << endl ;
    cout << fnct(5861,7) << endl ;

}