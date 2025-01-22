#include <iostream>
using namespace std ; 
namespace First {
    void show(){
        cout << "Hello World using namespace first . " << endl ; 
    }

}
namespace Second {
    void show(){
        cout << "Sum of 2 and 4 " << 2+4 << " using namespace Second" << endl ; 
    }
}
int main(){
    First::show();
    Second::show();
    }