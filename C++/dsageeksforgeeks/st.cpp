#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fl("student.txt");
    int sum = 0;
    int count = 0;
    string line;
    while (getline(fl, line))
    {
        int numindex = line.length() - 2;
        string num = line.substr(numindex);
        count++;
        cout << num;
    }
    cout << sum;
}