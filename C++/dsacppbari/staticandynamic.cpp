#include <stdio.h>
#include <iostream>
using namespace std; 
int main(){
    int n;
    cout << "Enter a number :" << endl;
    cin >> n;
    int A[n] = {0};
    int *p;
    p = new int[6];
    int *p1;
    p1 = (int *)malloc(5 * sizeof(int));
    delete[] p;
    free(p1);
}