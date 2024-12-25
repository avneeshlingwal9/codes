#include <iostream>
using namespace std;
template <class T>
void swapm(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
    return;
}
void permutations(int n, string &s, int i)
{
    if (i == n)
    {
        cout << s << " ";
        return;
    }
    for (int j = i; j < s.size(); j++)
    {
        swapm(s[i], s[j]);
        permutations(s, i + 1);
        swapm(s[i], s[j]);
    }
}
int main()
{
    int n = 3;  
    string s;
    permutations(n, s, 0);
}