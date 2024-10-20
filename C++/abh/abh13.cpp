#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    cout << "Name:- Anushka Negi" << endl ;
    cout << "Section:-  G1 "<< endl; 
    cout << "Roll No.: 11  " << endl; 
    string inputFileName, outputFileName;
    ifstream fin;
    ofstream fout;

       fin.open("this.txt");
    if (!fin) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    fout.open("output.txt");
    if (!fout) {
        cerr << "Error: Unable to open output file." << endl;
        fin.close();
        return 1;
    }

    char ch;
      while (fin.get(ch)) {
        
        fout.put(ch);
    }
   fin.close();
    fout.close();

   cout << "File contents copied with case changed successfully." << endl;

    return 0;
}
