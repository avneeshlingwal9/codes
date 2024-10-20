#include <iostream>
#include <string>
using namespace std;

class CRC {
private:
    string data;
    string divisor;
    int divisorLength;
    int dataLength;
    int codewordLength;
    string remainder;

    string extendDataWithZeros(string data, int numZeros);
    string xorStrings(string a, string b);
    void divide(string data, string divisor);

public:
    void sender();
    void receiver();
};

void CRC::sender() {
    cout << "Please enter the data: ";
    getline(cin, data);
    cout << "Please enter the divisor: ";
    getline(cin, divisor);

    dataLength = data.length();
    divisorLength = divisor.length();

    codewordLength = dataLength + divisorLength - 1;
    data = extendDataWithZeros(data, divisorLength - 1);

    divide(data, divisor);

    cout << "Sent codeword: " << data << endl;
    cout << "Divisor: " << divisor << endl;
}

void CRC::receiver() {
    string receivedData;
    cout << "Enter the received data: ";
    getline(cin, receivedData);
    divide(receivedData, divisor);

    if (remainder.find("1") == string::npos) {
        cout << "Data transmitted without error." << endl;
    } else {
        cout << "Data corrupted during transmission." << endl;
    }
}

string CRC::extendDataWithZeros(string data, int numZeros) {
    return data + string(numZeros, '0');
}

string CRC::xorStrings(string a, string b) {
    string result;
    for (size_t i = 0; i < a.length(); ++i) {
        result += (a[i] == b[i]) ? '0' : '1';
    }
    return result;
}

void CRC::divide(string data, string divisor) {
    int j = divisor.length();
    remainder = data.substr(0, j);

    for (size_t i = j; i < data.length(); ++i) {
        if (remainder[0] == '1') {
            remainder = xorStrings(remainder, divisor) + data[i];
        } else {
            remainder = xorStrings(remainder, string(j, '0')) + data[i];
        }
    }
}

int main() {
    CRC c;
    c.sender();
    c.receiver();
    return 0;
}
