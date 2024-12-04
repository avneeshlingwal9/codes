#include <bits/stdc++.h>
using namespace std;

void perm(string &num, int start, int k, vector<string> &allPerm)
{
    if (start == num.length() - 1 || k == 0)
    {
        allPerm.push_back(num);
        return;
    }
    for (int i = start; i <  num.size()-1 ; i++){

        swap(num[i+1], num[i]);
        perm(num, start + 1, k - 1, allPerm);
    
        }
    
    
}
void display(vector<string> comb){
    for(auto i: comb){
        cout << i << " ";
    }
    cout << endl; 
}
int main(){
    vector<string> comb;
    string num = "4321";
    perm(num, 0, 4, comb);
    display(comb);
}