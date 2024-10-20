#include <iostream>
using namespace std;
int main(){
    int *p, *q;
    p = new int[5];
    for (int i = 0; i <= 4;i++){
        p[i] = 2 * i;
    }
    q = new int[10];
    for (int i = 0; i < 5; i++){
        q[i] = p[i];
    }
    delete[] p;
    p = q;
    q = NULL;
    
}