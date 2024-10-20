#include <iostream>
#include <math.h>
using namespace std ;
int siter(int n){
    int sum = 0 ;
    for(int i = 1 ; i<= n ; i++)
    {
        sum += i*(floor(n/i));
    }
    return sum;
}
int main(){
    cout << siter(5) << " ";

}
