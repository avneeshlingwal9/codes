#include <iostream>
using namespace std;
long int  sumr(int n ){
    if(n==0){
        return 0; 
    }
    else{
    return sumr(n - 1) + n; }
}
long int sumf(int n ){
    return n * (n + 1) / 2; 
}
long int suml(int n ){
    int i, s = 0;
    for (i = 1; i <= n; i++){
        s += i;
    }
    return s;
}
int main(){
    int n = 10000;
    cout << "Sum formulae " << sumf(n) << endl;
    cout << "Sum loops " << suml(n) << endl;
    cout << "Sum recursion " << sumr(n) << endl;
    
}