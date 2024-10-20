#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Employee {
    int empno;
    string empname;
};

void addEmployee(const Employee& emp) {
    ofstream outputFile("Employee.txt", ios::app);

    if (!outputFile) {
        cerr << "Error: Unable to open the file for writing." << endl;
        return;
    }

    outputFile << emp.empno << ' ' << emp.empname << endl;

    cout << "Employee added successfully." << endl;

    outputFile.close();
}

void readEmployees() {
    ifstream inputFile("Employee.txt");

    if (!inputFile) {
        cerr << "Error: Unable to open the file for reading." << endl;
        return;
    }

    Employee emp;
    cout << "Employee List:" << endl;

    while (inputFile >> emp.empno >> emp.empname) {
        cout << "EmpNo: " << emp.empno << ", EmpName: " << emp.empname << endl;
    }

    inputFile.close();
}

void searchEmployee(const string& name) {
    ifstream inputFile("Employee.txt");

    if (!inputFile) {
        cerr << "Error: Unable to open the file for reading." << endl;
        return;
    }

    Employee emp;
    bool found = false;

    while (inputFile >> emp.empno >> emp.empname) {
        if (emp.empname == name) {
            cout << "Employee found - EmpNo: " << emp.empno << ", EmpName: " << emp.empname << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Employee with name '" << name << "' not found." << endl;
    }

    inputFile.close();
}

int main() {
    Employee emp;

    // Example: Adding an employee
    emp.empno = 101;
    emp.empname = "John Doe";
    addEmployee(emp);

    // Example: Reading all employees
    readEmployees();

    // Example: Searching for an employee by name
    searchEmployee("John Doe");

    return 0;
}
