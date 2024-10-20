#include <iostream>
using namespace std;
template <class T> 
void swa(T *a , T *b){
    T temp = *a ;
    *a = *b;
    *b = temp;
}
int fibbonacir(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1 ;

    }
    return fibbonacir(n-1)+fibbonacir(n-2);
}

int fibbonaci(int n){
    int first = 0 ;
    int second = 1 ;
    int i = 2;
    int curr = 0; 
    if(n == 0){
        return first;
    }
    if(n == 1){
        return second;
    }
    while(i <=n){
        curr = second+first;
        first = second;
        second = curr;
        i++;
        
    }
    return curr; 
}

int main(){
    cout << "Fibbonaci " << fibbonaci(6) << endl;
    string s = "ABCD";
    string b = "BACD";
    cout << "Before swapping " << s << " " << b << endl; 
    swa(&s,&b);
    cout << "After swapping " << s << " " << b << endl; 

}
