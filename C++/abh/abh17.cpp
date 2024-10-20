#include <iostream>
#include <vector>

using namespace std;

int main() {
     vector<int> myVector;

    cout << "Enter 10 numbers:\n";
    for (int i = 0; i < 10; ++i) {
        int num;
        cout << "Enter number " << i + 1 << ": ";
        cin >> num;
        myVector.push_back(num);
    }

       if (!myVector.empty()) {
        myVector.pop_back();
        cout << "Last element removed.\n";
    } else {
        cout << "Vector is empty.\n";
    }

    cout << "Elements of the vector in reverse order:\n";
    for (int i = myVector.size() - 1; i >= 0; --i) {
        cout << myVector[i] << " ";
    }

    return 0;
}
