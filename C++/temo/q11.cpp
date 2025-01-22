#include <iostream>
using namespace std ; 
void tower(int disks , char s ,char d, char a){
    if(disks == 1){
        cout << disks << " st is moved from " << s <<" to " <<  d << " "  << endl ;
    }
    else{
        tower(disks-1 , s , a , d);
        cout << disks << " nd moved from " << s << " to " << d << endl ;
        tower(disks-1,  a ,  d ,  s);
        }
    }
int main(){
    tower(3,'S','D','A');
}