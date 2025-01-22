#include <iostream>
#include <stack>
using namespace std ; 
void fm(stack <int> s);
int main(){
    stack <int> s ;
    int n ; 
    cout << "Enter the elements you want to enter in the stack " << endl ;
    cin >> n ; 
    
    for(int i = 0 ; i < n ; i++){
        int k ;
        cin >> k ;
        s.push(k);


    }
    cout << s.size() ;
    cout << s.top() ; 
}