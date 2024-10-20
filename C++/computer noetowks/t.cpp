#include <iostream>
#include <unistd.h>
#include <ctime>
using namespace std;
int prob(){
    return rand();
}
int main(){
    string num ="hello";
    cout << num.length() << endl ;
    string ref = "wor";
    num = num.substr(ref.length());
    cout << num << endl;

    

}