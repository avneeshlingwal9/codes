#include <iostream>
#include <fstream>
using namespace std;

int main()

{
    ofstream myfile("new.txt");
    cout << "Enter the contents of the file: " << endl;
    string line;
    while (getline(cin, line))
    {
        for (int i = 0; i < line.length(); i++)
        {
            if (isupper(line[i]))
            {
                line[i] = tolower(line[i]);
            }
        }
        myfile << line << endl;
    }
}