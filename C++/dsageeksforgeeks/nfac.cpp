
#include <bits/stdc++.h>
using namespace std;
void fill(vector<long long> &ans, int f, long long &n, int i)
{
    if (f * i > n)
    {
        return;
    }
    f *= i;
    ans.push_back(f);
    i++;
    fill(ans, f, n, i);
}
vector<long long> factorialNumbers(long long n)
{
    // Write Your Code here
    vector<long long> ans;
    fill(ans, 1, n, 1);
    return ans;
}
int main()
{
    map<pair<int, int>, char> dir{{{1, 0}, 'D'}, {{-1, 0}, 'U'}, {{0, -1}, 'L'}, {{0, 1}, 'R'}};
    for (auto it : dir)
    {
        cout << it.first.first << " " << it.first.second << " " << it.second << endl;
    }
}