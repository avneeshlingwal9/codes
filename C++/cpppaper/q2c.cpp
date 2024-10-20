#include <iostream>
using namespace std;

class BankAccount {
    static int accountcount;
public:
    string name;
    string address;
    string type;
    double balance;
    string accountnumber;
    int transactions;
    BankAccount(){
        name= "nil";
        address = "nil";
        type ="nil";
        balance = -1 ;
        accountnumber = "nil";
        transactions = 0 ;
    }

    // Constructor with parameters
    BankAccount(string aname, string aaddress, string atype, double abalance) {
        name = aname;
        address = aaddress;
        type = atype;
        balance = abalance;
        transactions = 0;
        accountnumber = accountgenerator();
    }

    // Function to generate account number
    string accountgenerator() {
        return "BA" + to_string(accountcount++);
    }

    void display() {
        cout << "Name: " << name << ", Account Number: " << accountnumber << ", Balance: " << balance << endl;
    }

    void deposit(double b) {
        balance += b;
        transactions++;
        cout << "Balance is " << balance << endl;
    }

    void withdraw(double a) {
        if (a <= balance) {
            balance -= a;
            transactions++;
            cout << "Balance is: " << balance << endl;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    void changeaddress(string s) {
        address = s;
        cout << "Address updated." << endl;
    }
};

// Initialize the static variable outside the class definition
int BankAccount::accountcount = 1000;

int main() {
    int n;
    cout << "Enter the number of depositors: ";
    cin >> n;

    BankAccount b[n];

    // Initialize each BankAccount object with some default values
    for (int i = 0; i < n; i++) {
        b[i] = BankAccount("J", "12", "Savings", 5000.0);
    }

    // Display information for each account
    for (int i = 0; i < n; i++) {
        b[i].display();
    }

    return 0;
}
