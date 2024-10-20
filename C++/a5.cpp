#include <iostream>
using namespace std;
class Netger{
    private:
     int s ;
    public :
    Netger(){
        cout << "Enter a number: - " << endl ;
        cin >> s ;
    }
    string operator+(const string b) {
    return to_string(s)+b;

}};





int main(){
    Netger n ;
    string s = n+"hello";
    cout << s ; 

}
