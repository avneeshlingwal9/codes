#include <iostream>
using namespace std;
int hcf(int a , int b){
    if(a%b == 0){
        return b;
    }
    return hcf(b, a % b);
}
int main(){
    cout << hcf(12, 40);
}