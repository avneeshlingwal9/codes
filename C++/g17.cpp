#include <iostream>
#include <fstream>
using namespace std;

int main() {
    cout << "Name:- Anushka Negi  " << endl;
    cout << "Section:- G1 " << endl;
    cout << "Roll No.:- 11 " << endl;

    ofstream f;
    f.open("h.txt", ios::out);
    string l;
    int n;

    cout << "Enter the number of lines you want to enter: - " << endl;
    cin >> n;

    cin.ignore(); // Ignore newline character in the input buffer

    for (int i = 0; i < n; i++) {
        cout << "Enter the line: - " << endl;
        getline(cin, l);
        
        if (i == 0) {
            f << l;
        } else {
            f << endl << l;
        }
    }

    f.close();

    ifstream g;
    string m;
    ofstream o;
    g.open("h.txt", ios::in);
    o.open("o.txt", ios::out);

    while (getline(g, m)) {
        if (m == "-1") {
            break;
        } else {
            o << m << endl;
        }
    }

    g.close();
    o.close();

    ifstream b;
    b.open("o.txt", ios::in);

    cout << "Contents of o.txt:" << endl;

    while (getline(b, m)) {
        cout << m << endl;
    }

    b.close();

    return 0;
}
