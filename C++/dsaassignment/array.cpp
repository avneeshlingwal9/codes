#include <iostream>
#include <algorithm>
using namespace std;
// Function to swap two elements
template <class T>
void swap(T* a , T* b){
    T temp = *a;
    *a = *b;
    *b = temp;
}
template <class T>
int partition(T *A, int low , int high){
    T piv = A[low];
    int i = low;
    int j = high;
    while(i < j){
        while(A[i] <= piv && i < high){
            i++;
        }
        while(A[j] > piv && j > low){
            j--;
        }
        if(i < j){
            swap(&A[i], &A[j]);
        }

    }
    swap(&A[low], &A[j]);
    return j; 
}
/*
Finds right position of an element , by traversing through the array.
Time Complexity: O(N)


*/
template <class T>
int findRightPosition(T *A , int begin , int end , T el){
    for (int i = begin; i <  end; i++){
        if(A[i] > el){
            return i;
        }
    }
    return end;
}
/*
Shifts the elements of the array, based on a particular given position.
Time Complexity: O(N)

*/
template <class T>
void shifting(T *A , int pos, int size , T el ){
    for (int i = size; i > pos ; i--){

        A[i] = A[i - 1];
    }
    A[pos] = el;
}





//Sorting the elements using quicksort 
template <class T>
void quickSort(T *A ,int begin , int end){
    if(begin < end){
        int pivot = partition(A, begin, end);
        quickSort(A, begin, pivot - 1);
        quickSort(A, pivot + 1, end);
    }
}
// Class Defined for array with member variables as size and data . 
template <class T>
class Array{
    public:
        int size;
        T *data;
// Two constructors to for declaration of the array 
    Array(){
        data = NULL;
        size = 0;
    }
    Array(int siz){
        data = new T[siz];
        size = siz;
       
    }
//Insert function to insert elements in the array
    void insert(){
        cout << "Insert the elements of the array " << endl;
        for (int i = 0; i < size; i++){
            cin >> *(data + i);
        }
    }
    
// Function to display elements of the array.
void display(){
    cout << "Elements of the array are : " << endl; 
    for (int i = 0; i < size; i++){
        cout << *(data+i)<< " ";
    }
    cout << endl;
}
// Function to reverse the given array
//  Time complexity is : O(end-start/2) as we are iterating only half of the array.
void reverse(int start , int end){
    int last = end;
    int first = start;
    while(first < last){
        swap(&data[first], &data[last]);
        first++;
        last--;
    }
}
// Function to left rotate using the reverse function
// Time Complexity : O(N)
// Space Complexity : O(1);
void left_rotate(int k){
    k = k % size;
    reverse(0, k-1); // O(K-1/2)
    reverse(k, size-1); // O(size-k/2)

    reverse(0, size-1);  // O(size/2)
}
// Function to right rotate the array using the reverse function
// Time Complexity : O(N)
// Space Complexity : O(1)
void right_rotate(int k){
    k = k % size;
    k = size - k;
    reverse(0, k - 1);
    reverse(k, size - 1);
    reverse(0, size - 1);
}
// Function to return previous element of the last inserted element
T back(int index){
    return index > 0 ? data[index - 1] : -1;
}




};
template <class T>
// Function to find intersection and return it 
Array<T> intersection_arrays(Array<T> A , Array<T> B ){
    int size = min(A.size, B.size); 
    // As the maximum size of the intersection of two arrays will be equal to the size of the smallest array.
    Array<T> ans(size);
    quickSort(A.data, 0, A.size-1); // O(mlogm)
    quickSort(B.data, 0, B.size-1); // O(nlogn)
    /* 
    Sorting both the arrays so that we can find intersecting pairs in one traversal 
    */
    int indA = 0; // To keep track of indices of A
    int indB = 0 ;  // To keep track indices of B
    int indans = 0; // To keep track of indices of ans
                    // while loop runs for O(min(m,n));
    while(indA < A.size && indB < B.size){ 
        if(A.data[indA] < B.data[indB]){
            indA++;
        }
        else if(A.data[indA] > B.data[indB]){
            indB++;
        }
        else{
            ans.data[indans++] = A.data[indA++];
            indB++;
        }
    }
    ans.size = indans;

    return ans;
    // So total time comlpexity is O(mlogm)+ O(nlogm)+O(min(m,n))
    //  Space complexity is O(min(m,n)) , As maximum intersecting elements can be min(m,n)
}
template <class T>
// Function to find union of two arrays 
Array<T> union_array(Array<T> A, Array<T> B)
{
    int indA = 0;
    int indB = 0;
    int indans = 0;
    Array<T> ans(A.size + B.size); // Creating ans array of m+n for worst case 
    
    // Sorting both the arrays 
    quickSort(A.data, 0, A.size-1);   // O(NlogN)
    quickSort(B.data, 0, B.size-1);  // O(MlogM)
    while(indA < A.size && indB < B.size){
        /* Inserting new element only if the element does not exist in the array checking through back function for
        previous element which was inserted as both arrays are sorted so it prevents duplicate elements 
        Total Time Complexity : While loops will run total of O(M+N) + O(NlogN)+ O(MlogM)
        Total Space Complexity : O(M+N) if every is unique in both the arrays
        
         */
        if(A.data[indA] == ans.back(indans)){
            indA++;
        }
        else if(B.data[indB] == ans.back(indans)){
            indB++;
        }
        else if(A.data[indA] <= B.data[indB] ){
            ans.data[indans++] = A.data[indA++];
        }
        else{
            ans.data[indans++] = B.data[indB++];
        }
    }
    // If any of the array is exhausted then putting them into the answer array .
    while(indA < A.size){
        if(A.data[indA] != ans.back(indans)){
            ans.data[indans++] = A.data[indA++];
        }

    }
    while(indB < B.size){
        if(B.data[indB] != ans.back(indans)){
            ans.data[indans++] = B.data[indB++];
        }
    }
    ans.size = indans; // Updating the size of the answer array .
    return ans;
}

/* int main(){
    Array<int> a(6);
    a.insert();
    a.display();
    int rotate;
    cout << "Enter the places for array to be rotated left " << endl;
    cin >> rotate;
    a.left_rotate(rotate);
    a.display();
} */