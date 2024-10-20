#include <iostream>

class ObjectCounter {
private:
static int count;     
int id;
public:
    ObjectCounter() {
        count++;      
   id = count;
    }

    ~ObjectCounter() {
        count--; 
    }

    static int getCount() {
        return count; 
    }

};
int ObjectCounter::count = 0;

using namespace std;

int main() {
    ObjectCounter obj1;
    ObjectCounter obj2;
    ObjectCounter obj3;

cout << "Number of objects created: " << ObjectCounter::getCount() << endl;

    return 0;
}
