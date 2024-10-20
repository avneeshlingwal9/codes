#include <bits/stdc++.h>
using namespace std;
int main(){
    int n = -12121;
    int d = n; 
    int rev = 0;
    while(n){
        rev = rev * 10 + n % 10;
        cout << "n%10 " << n % 10 << " "; 
        n = n / 10;
        

    }
    cout << rev << endl;
    cout << (d == rev);
}p