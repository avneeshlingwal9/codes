#include <iostream>
#include <stdexcept>

using namespace std;

class MyNation : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid Nationalistic Spirit: The string should be 'jai hind' or 'JAI HIND'.";
    }
};

void checkNationalisticSpirit(string& str) {
    if (str != "jai hind" && str != "JAI HIND") {
        throw MyNation();
    }
}

int main() {
    string userInput;

    try {
        cout << "Enter the nationalistic spirit: ";
        getline(cin, userInput);

        checkNationalisticSpirit(userInput);

        cout << "Nationalistic spirit is valid: " << userInput << endl;
    } catch (const MyNation& e) {
        cerr << "Exception caught: " << e.what() << endl;
    }

    return 0;
}
