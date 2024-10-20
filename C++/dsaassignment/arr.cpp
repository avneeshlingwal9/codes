#include <bits/stdc++.h>


using namespace std ;
int *Create(int n){
    int* A = new int[n];
    cout <<"Enter the elements of the array : " << endl;
    for(int i = 0 ; i < n ; i++){
        cin >> A[i];
    }
    return A;
}
int * Intersection(int *A , int n , int *B , int m){
    int *C = new int[m+n];
    int i = 0 , j = 0 , k = 0;
    while(i < n && j < m){
        if(A[i] == B[j]){
            C[k++] = A[i];
            i++;
            j++;
        }
        else if(A[i] < B[j]){
            i++;
        }
        else if (B[j] < A[i]){
            j++;
        }
    }
    return C;

}
void display(int *C , int s){
    for(int i = 0 ; i < s ; i++){
        cout << C[i] << " ";
    }
}
int main(){
    int n , m;
    cout <<"Enter the number of elements for both arrays: " << endl;
    cin >> n >> m ;
    int *A = Create(n);
    sort(A,A+n);
    int *B = Create(m);
    sort(B,B+m);
    int *C = Intersection(A,n,B,m);
    int sz = sizeof(C)/sizeof(C[0]);
    display(C,sz);





}