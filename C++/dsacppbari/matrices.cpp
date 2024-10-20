#include <iostream>
#include <unistd.h>
#include <stdlib.h>
using namespace std; 
class diagonalMatrix{
    private:
        int n;
        int *A; 
    public: 
    diagonalMatrix(){
        n = 2;
        A = new int[n];
    }
    diagonalMatrix(int n ){
        this->n = n;
        A = new int[n];
    }
    void set(int i, int j, int ele);
    int get(int i, int j);
    void display();
    ~diagonalMatrix(){
        delete[] A;
    }
};
class upperTriangularMatrix{
    private:
        int n;
        int *A;
    public:
    upperTriangularMatrix(){
        n = 2;
        A = new int[n * (n + 1) / 2];

    }
    upperTriangularMatrix(int n){
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }
    void setColumnMajor(int i, int j , int el){

        if(i<=j){
            A[j * (j - 1) / 2 + i - 1] = el; 
        }
    }
    void setRowMajor(int i , int j , int el){
        if(i<=j){
            A[(i - 1) * n - (i - 2) * (i - 1) / 2 + j - i] = el;
        }
    }
    int getColumnMajor(int i, int j){
        if(i<=j){
            return A[j * (j - 1) / 2 + i - 1];
        }
        return 0; 
    }
    int getRowMajor(int i , int j){
        if(i<=j){
            return A[(i - 1) * n - (i - 2) * (i - 1) / 2 + j - i];
        }
        return 0; 
    }
    void displayRow(){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n;j++){
                if(i <= j){
                    cout << A[(i - 1) * n - (i - 2) * (i - 1) / 2 + j - i] << " ";

                }
                else{
                    cout << "0 "; 
                }
            }
            cout << "\n";
        }
    }
    void displayColumn(){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if(i<=j){
                    cout << A[j * (j - 1) / 2 + i - 1] <<" ";
                }
                else{
                    cout << "0 ";
                }
            }
            cout << "\n";
        }
    }

    
};

class lowerTriangularMatrix{
    private:
        int n;
        int *A; 
    public:
    lowerTriangularMatrix(){
        n = 2;
        A = new int[n*(n+1)/2];
    }
    lowerTriangularMatrix(int n){
        this->n = n;
        A = new int[n*(n+1)/2];

    }
    void setRowMajor(int i , int j , int el){
        int index = 0; 
        if(i>=j){
            index = ((i * (i - 1)) / 2) + j - 1;
            A[index] = el;
        }

    }
    void setColumnMajor(int i , int j , int el){
        int index = 0;
        if(i>=j){
            index = n * (j - 1) - (j - 2) * (j - 1) / 2 + (i - j);
            A[index] = el;
        }
    }
    int getRowMajor(int i , int j , int el){
        int index = 0; 
        if(i>=j){
            index = i * (i - 1) / 2 + j - 1;
            return A[index];
        }
        return 0; 
    }
    int getColumnMajor(int i , int j , int el){
        int index = 0; 
        if(i >=j){
            index = n * (j - 1) - (j - 2) * (j - 1) / 2 + (i - j);
            return A[index];
        }
    }
    void displayRowMajor(){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n;j++){
                if(i>=j){
                    int in = i * (i - 1) / 2 + j - 1;
                   cout << A[in] << " "; 
                }
                else{
                    cout << "0 ";
                }
            }
            cout << endl; 
        }
    }
    void displayColumnMajor(){
        for (int i = 1; i <= n; i ++){
            for (int j = 1; j <= n; j++){
                if(i>=j){
                    int in = n * (j - 1) - (j - 2) * (j - 1) / 2 + (i - j);
                    cout << A[in] << " ";
                }
                else{
                    cout << "0 ";
                }
            }
            cout << endl; 
        }
    }
    ~lowerTriangularMatrix(){
        delete[] A;
    }


};
void diagonalMatrix::set(int i , int j , int ele){
    if(i==j){
        A[i] = ele;
    }
}
int diagonalMatrix::get(int i , int j){
    if(i==j){
        return A[i];
    }
    return 0; 
}
void diagonalMatrix::display(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i == j){
                cout << A[i] << " ";
            }
            else{
                cout << "0 ";
            }
        }
        cout << endl; 
    }
}
int main(){
    int n, x, i, j; 
    cout << "Enter the dimensions :" << endl;
    cin >> n;
    upperTriangularMatrix u(n);
    cout << "Enter the elements of the array: " << endl;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> x;
            u.setRowMajor(i, j, x);
        }
    }
    cout << "\n";

    
    u.displayRow();
}