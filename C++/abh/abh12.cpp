#include <iostream>
#include <stdexcept>

using namespace std;

class InvalidAgeException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid Age: Age must be 18 or older.";
    }
};

void checkAge(int age) {
    if (age < 18) {
        throw InvalidAgeException();
    }
}

int main() {
    int userAge;

    cout << "Enter your age: ";
    cin >> userAge;

    try {
        checkAge(userAge);
        cout << "Age is valid: " << userAge << endl;
    } catch (const InvalidAgeException& e) {
        cerr << "Exception caught: " << e.what() << endl;
    }

    return 0;
}
