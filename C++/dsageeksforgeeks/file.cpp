#include <iostream>
#include <fstream>
using namespace std;
void readingFile(string fileName)
{
    ofstream myFile(fileName);
    int numOfLine;
    cout << "Enter the number of lines you want to insert: " << endl;
    cin >> numOfLine;
    string line;
    cin.ignore();
    for (int i = 0; i < numOfLine; i++)
    {
        getline(cin, line);
        myFile << line << endl;
    }
    myFile.close();
}
void understandingFile(string fileName)
{
    ifstream myFile(fileName);
    string line;
    string date;
    string time;
    string purpose;
    while (getline(myFile, line))
    {
        date = line.substr(0, 10);
        time = line.substr(11, 5);
        purpose = line.substr(17, string::npos);
        cout << date << " " << time << " " << purpose << endl;
    }
    myFile.close();
}
int getVowelCount(string s)
{
    int vCount = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] == 'A' || s[i] == 'a') || (s[i] == 'E' || s[i] == 'e') || (s[i] == 'I' || s[i] == 'i') || (s[i] == 'O' || s[i] == 'o') || (s[i] == 'U' || s[i] == 'u'))
        {
            vCount++;
        }
    }
    return vCount;
}
void countNum(string fileName)
{
    ifstream myFile(fileName);
    string line;
    int totalCount = 0;
    int vCount = 0;
    while (getline(myFile, line))
    {
        totalCount += line.length();
        vCount += getVowelCount(line);
    }
    cout << "Total number of characters are: " << totalCount << endl;
    cout << "Total number of vowels are: " << vCount << endl;
    myFile.close();
}
int main()
{
    string fileName;
    cout << "Enter the filename: " << endl;
    getline(cin, fileName);
    understandingFile(fileName);
}