#include <iostream>
#include <stdio.h>
#include <stdlib.h>



using namespace std;
int main(){
    int A[3][3] = {{1, 2, 1}, {6, 7, 8}, {9, 4, 5}};
    int *p[3];
    p[0] = (int *)malloc(4*sizeof(int));
    p[1] = (int *)malloc(4 * sizeof(int));
    p[2] = (int *)malloc(4 * sizeof(int));
    for (int i = 0; i < 3;i++){
        for (int j = 0; j < 4; j++){
            cout << p[i][j] << " "; 
        }
        cout << endl; 
    }
        free(p[0]);
    free (p[1]);
    free (p[2]);
    int **d;
    d = (int **)malloc(3* sizeof(int*));
    d[0] = (int *)malloc(4 * sizeof(int));
    d[1] = new int[4];
    d[2] = new int[4];
    cout << "Array D " << endl; 
    for (int i = 0; i < 3;i++){
        for (int j = 0; j < 4; j++){
            cout << d[i][j] << " ";
        }
        cout << endl; 
    }

    delete[] d[0];
    delete[] d[1];
    delete[] d[2];
    return 0; 
}
