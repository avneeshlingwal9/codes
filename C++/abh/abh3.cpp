#include <iostream>
using namespace std;
class MyClass {
public:
    int data;

    MyClass(int value){
        this->data=value;
    }
};

int main() {
    MyClass* ptr;
    ptr = new MyClass(42);
   cout << "Value of data: " << ptr->data << endl;
    
    delete ptr;
 return 0;
}
