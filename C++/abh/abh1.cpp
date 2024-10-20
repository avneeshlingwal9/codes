#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    int age;
    string employeeCode;

public:
     Employee(const string& n, int a, const string& code) {
        this->name=n;
        this->age=a;
        this->employeeCode=code;
    }
  
 int operator-(const Employee& other) const {
        return abs(age - other.age);
    }

       void display() const {
        cout << "Name: " << name << ", Age: " << age << ", Employee Code: " << employeeCode << endl;
    }
};

int main() {
        Employee emp1("John", 30, "E001");
    Employee emp2("Alice", 25, "E002");
 cout << "Employee 1: ";
emp1.display();
cout << "Employee 2: ";
    emp2.display();

        int ageGap = emp1 - emp2;
    cout << "Age gap between Employee 1 and Employee 2: " << ageGap << " years" << endl;

    return 0;
}
