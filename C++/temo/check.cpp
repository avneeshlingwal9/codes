#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
    ofstream file("aa.txt");

    vector<int> ans{4, 5, 6};
    for (auto i : ans)
    {
        file << i << " ";
    }
}