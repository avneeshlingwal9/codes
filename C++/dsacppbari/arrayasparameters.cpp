#include <iostream>
using namespace std ;
int * um( int n ){
    int *p;
    p = new int[n];
    for (int i = 0; i < n; i++){
        p[i] = i;
    }
    return p;
}
int main(){
    int * a =  um(5);
    for (int i = 0; i < 5; i++){
        cout << a[i] << endl; 
    }
}