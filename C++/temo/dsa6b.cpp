#include <iostream>
using namespace std ;
int f(int x){
    if(x<2){
        return 1 ;

    }
    return f(x-1)+f(x-2);
}
int main(){
    int n = f(5);
    cout << n << endl ;
}