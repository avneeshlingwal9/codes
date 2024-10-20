#include <iostream>
using namespace std ;
void  fg(int n){
    if (n > 0 ){
        fg(n-1);
        cout << n*n  << " " ;
    }


}
int main(){
    fg(7);

}