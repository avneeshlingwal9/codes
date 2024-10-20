#include <iostream>
using namespace std;
//Function to create an 2-D matrix.
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

//Function to display a 2-D matrix 
// Input Parameters as row and column number
// Time Complexity: O(m*n)
void display(int **A , int m , int n){

    for(int i = 0 ; i < m ; i++){
        for(int j=0 ; j < n ; j++){
            cout << A[i][j] << " ";
        }
        cout << endl; 
    }
} 
//Function to create an empty 2-D matrix
int ** vcreate(int m , int n){
    int **B = new int*[m];
    for(int i = 0 ; i < m ; i++){
        B[i] = new int[n];

    }
    return B;

}
// Transposing a matrix and then storing the result into another matrix B
// Time Complexity: O(r*c)
// Space Complexity: O(r*c)
void transpose(int **A, int **B, int r, int c)
{
    for(int i =0 ; i < r ; i++){
        for(int j = 0 ; j < c; j++){
            B[j][i] = A[i][j];
        }
    }
}

/*Function to print spiral of a matrix
Using four variables :
Top -> Keeps track of the uppermost row
Bottom -> Keeps track of the lowermost row
Left -> Keeps track of the leftmost column
Right -> Keeps track of the rightmost column
Time Complexity : - O(M*N);



*/
void spiral(int **A , int r , int c){
    int top = 0, bottom = r - 1, left = 0, right = c - 1;
    while(top <= bottom && left <= right){
        for (int i = left; i <= right; i++){
            cout << A[top][i] << " ";
        }
        top++;
        for (int i = top; i <= bottom; i++){
            cout << A[i][right] << " ";
        }
        right--;
        if(top <= bottom){
        for (int i = right; i >= left; i--){
            cout << A[bottom][i] << " ";
        }}
        bottom--;
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--){
                cout << A[i][left] << " ";
            }
        }
        left++;
    }
}

int main(){
    int m , n ;  //Row and column number 
    cout << "Enter number of rows and columns of the array : " << endl;
    cin >> m >> n ;
    int **A = create(m,n); 
    cout << "Elements of the array  in the spiral are : " << endl; 
    spiral(A,m,n);
  
 
}