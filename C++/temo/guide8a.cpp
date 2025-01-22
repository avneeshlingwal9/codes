#include <iostream>
using namespace std ;
void towerofhanoi(int n , char begin , char aux , char dest){
if(n==0){
    return ;
}
towerofhanoi(n-1 ,begin , dest,aux);
cout << n <<" th Disk moved from " << begin << " to " << dest << endl ;
towerofhanoi(n-1,aux,begin,dest);
}
int main(){
    towerofhanoi(4,'A','B','C');
}