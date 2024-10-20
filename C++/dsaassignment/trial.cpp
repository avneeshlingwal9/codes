#include <iostream>
using namespace std;
int main(){
    int siz = 4;
    int *data = new int[siz];
        
        cout << "Enter the elements of the array: " << endl;
        for (int i = 0; i < siz; i++){
            cin >> data[i];
        }

}