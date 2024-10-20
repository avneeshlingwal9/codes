#include <iostream>
using namespace std; 
void swp(int *a , int *b){
    int c = *a;
    *a = *b;
    *b = c; 
}
class Array{
    private :
        int *A;
        int size;
        int length; 
    public :
    Array(){
        size = 10;
        A = new int[size];
        length = 0; 

    }
    Array(int sz){
        size = sz;
        A = new int[size];
        cout << "Enter the number of elements you want to insert in the array: " << endl;
        cin >> length;
        cout << "Enter them " << endl;
        for (int i = 0; i < length; i++){
            cin >> A[i];
        }
    }
    void display(){
        cout << "Elements of the array are : " << endl; 
        for (int i = 0; i < length; i++){
            cout << A[i] << " "; 
        }
        cout << endl; 
    }
    void append(int x){
        if(length < size){
            A[length++] = x; ;
        }
        else{
            cout << "Array already full " << endl;
         }
    }
 
    int dlete(int index){
        int x = 0;

        if(index >=0 && index < length){
            x = A[index];
            for (int i = index; i < length - 1; i++){
                A[i] = A[i + 1];
            
            }
            length--;
            return x;
        }
        return x; 
    }
    int linearsearch(int key){
        for (int i = 0; i < length - 1; i++){
            if(A[i] == key){
                return i; 
            }
        }
        return -1;
    }
    int linearsearchtransportation(int key){
        for (int i = 0; i < length - 1; i++){
            if(A[i] ==key ){
                swp(&A[i],&A[i-1]);
                return i - 1;
            }
        }
        return -1;
    }
    int linearsearchmovetofront(int key){
        for (int i = 0; i < length - 1; i++){
            if(A[i] == key){
                swp(&A[i],&A[0]);
                return 0;
            }
        }
        return -1;
    }
    int ibinarySearch(int x){
        int l = 0, h = length - 1, mid = 0;
        
        while (l<= h){
            mid = (l + h) / 2;

            if(A[mid]==x){
                return mid;
            }
            else if(x < A[mid]){
                h = mid - 1; 
            }
            else{
                l = mid + 1;
            }
        }
        return -1;
    }
    int rbinarySearch(int l , int h, int key ){
        int mid = (l + h) / 2;
        if(l > h){
            return -1;
        }
        else{
            if(A[mid]==key ){
                return mid;
            }
            else if(key < A[mid]){
                return rbinarySearch(l, mid - 1, key);
            }
            return rbinarySearch(mid + 1, h, key);
        }
    }
    int get(int index){
        if(index>=0 && index< length){
        return A[index];}
        return -1; 
    }
    void set(int index , int x){
        if(index>=0 && index< length){
            A[index] = x; 
        }
    }
    void insert(int index , int x){
        if(index>=0 && index <= length){
            int i = length - 1; 
            while(i >= index){
                A[i+1] = A[i];
                i--;
            }
            A[index] = x;
            length++;
        }
        else{
            if(length==size){
                cout << "Array already full " << endl;
            }
            else{
                cout << " Fucking diabbolical invalid index you cunt " << endl;
            }
        }
    }
    int max(){
        int max = A[0];
        for (int i = 1; i < length; i++){
            if(A[i] > max){
                max = A[i];
            }
        }
        return max;
    }
    int min(){
        int min = A[0];
        for (int i = 0; i < length; i++){
            if(A[i] < min){
                min = A[i];
            }
        }
        return min; 
    }
    int sum(){
        int total = 0;
        for (int i = 0; i < length; i++){
            total += A[i];
        }
        return total;
    }
    int rsum(int n ){
        if(n < 0 ){
            return 0;
        }
        return A[n] + rsum(n - 1);
    }
    int getlength(){
        return length;
    }
    float avg(){
        return sum() / length;
    }
    void reversearr(){
        int i = 0, j = length - 1; 
        while(i<j){
            swp(&A[i], &A[j]);
            i++;
            j--;
        }
    }
    void leftshift(){
        for (int i = 1; i < length - 2; i++){
            A[i - 1] = A[i];
        }
        A[length - 1] = 0;
    }
    void leftrotate(){
        int x = A[0];
        for (int i = 1; i < length - 2; i++){
            A[i - 1] = A[i];
        }
        A[length - 1] = x; 
    }

    
};
int main(){
    Array a(15);
    int x = 10;
    int index = 5;
    a.display();

    a.reversearr();
    a.display();
    a.leftshift();
    a.display();
}