#include <iostream>
using namespace std;

/*Reversing a string using swap function.
Approach: 
We will initialize two pointers one from front, another from back and until they meet we will swap the the corresponding characters at corresponding indexes. 
So overall Time Complexity of this approach would be : O(N/2) where N is the length of string

*/
template<class T>

void swap(T*a , T*b){
    T temp = *a;
    *a = *b;
    *b = temp;
}
void reverseString(string &s){
    int len = s.length();
    int i = 0;
    int j = len - 1;
    while(i<=j){
        swap(&s[i], &s[j]);
        i++;
        j--;
    }
}
int main(){
    string s = "Bye World";
    cout << "Original String " << s << endl;
    reverseString(s);
    cout << "Reversed String " << s << endl;
}