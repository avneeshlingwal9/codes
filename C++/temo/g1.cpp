#include <iostream> 
using namespace std ; 

int main(){
    int x,y,z ; 
    cout << "Enter three numbers :- \n";
    cin >> x >> y >> z ; 
    if (x > y & x > z ){
        cout << x << " is the greatest number . \n" ;
    }
    else if ( y > x & y > z ){
        cout << y << " is the greatest number of the three . \n";
    }
    else if ( x == y & y == z ){
        cout << "All three numbers are equal and number is : - " << x << endl ; 
    }
    else {
        cout << z << " is the greatest number of the three.\n ";
    }
    return 0 ; 
}