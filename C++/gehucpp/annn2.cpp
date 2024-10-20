#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    cout << "Name:- Anushka Negi  " << endl ;
    cout << "Section:- G1 " << endl ;
    cout << "Roll No.:- 11 " << endl;  
    string inputFileName, outputFileName;

    
    cout << "Enter the input file name: ";
    getline(cin, inputFileName);

    // Open input file
    ifstream fin(inputFileName);
    if (!fin) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    // Get output file name from user
    cout << "Enter the output file name: ";
    getline(cin, outputFileName);

    // Open output file
    ofstream fout(outputFileName);
    if (!fout) {
        cerr << "Error: Unable to open output file." << endl;
        fin.close();
        return 1;
    }

    // Read contents from input file and write to output file
    char ch;
    while (fin.get(ch)) {
        fout.put(ch);
    }

    // Close files
    fin.close();
    fout.close();

    // Display contents to the user
    ifstream displayFile(outputFileName);
    if (!displayFile) {
        cerr << "Error: Unable to open output file for display." << endl;
        return 1;
    }

    cout << "File contents:" << endl;
    while (displayFile.get(ch)) {
        cout.put(ch);
    }

    displayFile.close();

    cout << "\nFile contents copied successfully." << endl;

    return 0;
}
