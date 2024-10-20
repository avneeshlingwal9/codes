#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int countCharacters(const string& line) {
    return line.length();
}

int countWords(const string& line) {
    stringstream ss(line);
    string word;
    int wordCount = 0;

    while (ss >> word) {
        wordCount++;
    }

    return wordCount;
}

int countLines(ifstream& file) {
    string line;
    int lineCount = 0;

    while (getline(file, line)) {
        lineCount++;
    }

    return lineCount;
}

int main() {
    ifstream inputFile;


    inputFile.open("this.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open the file." << endl;
        return 1;
    }

    int charCount = 0;
    int wordCount = 0;
    int lineCount = 0;
    string line;


    while (getline(inputFile, line)) {
        charCount += countCharacters(line);
        wordCount += countWords(line);
        lineCount++;
    }


    inputFile.close();


    cout << "Number of characters: " << charCount << endl;
    cout << "Number of words: " << wordCount << endl;
    cout << "Number of lines: " << lineCount << endl;

    return 0;
}


