#include <iostream>
using namespace std ; 
int hcf(int n1 , int n2 );
int main(){
    int a , b  ;
    printf("Enter a number : - ");
    cin >> a >> b ; 
    cout << hcf(a,b);

    
}
int hcf(int n1 , int n2 ){
    if((n1 > 0 )&&(n2 > 0 )){
        if(n1%n2 != 0){
            return(hcf(n2 , n1%n2));
        }
        else {
            return n2 ; 
        }
    }
    else {
        return -1 ;
    }
    }
