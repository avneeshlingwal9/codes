#include <iostream>
using namespace std ; 
int fibbonicci(int n){
    if(n <=3){
        return 1 ;
    }
    return fibbonicci(n-1)+ fibbonicci(n-2);
}
int main(){
    cout << "Fibbonicci series: " << endl ; 
    cout << fibbonicci(19) ;

}