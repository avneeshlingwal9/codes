#include <iostream>
using namespace std;


int ** vcreate(int m , int n){
    int **B = new int*[m];
    for(int i = 0 ; i < m ; i++){
        B[i] = new int[n];

    }
    return B;

}
int ** create(int m , int n){
    int **A = new int*[m];
    for(int i = 0 ;i < m ; i++)
   {
    A[i] = new int[n];
   }
   cout << "Enter elements of the array : " << endl;
   for(int i =0 ; i < m ; i++){
    for(int j =0 ; j < n ; j++){
        cin >>A[i][j];
    }
   }
   return A;


}
void display(int** A , int r , int c){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
// Adding two matrices and then displaying them 
// Time Comlexity : O(r*c) 
// Space Complexity : O(r+c)
void summ(int** A , int** B, int r , int c){
    int **C = vcreate(r, c);
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    display(C, r, c);
}

int main(){
    int r, c;
    cout << "Enter the number of rows and columns for the matrices that you want to sum " << endl;
    cin >> r>> c; //Taking row number and column number as user input 
    int **A = create(r, c);  // Using create function to create two 2-D matrices
    int **B = create(r, c);
    cout << "Elements of array A : " << endl;
    display(A, r, c); // Displaying both the matrices 
    cout << "Elements of array B : " << endl;
    display(B, r, c);
    cout << "Elements of the array after sum : " << endl;
    summ(A, B, r, c); // Calling the sum function
}