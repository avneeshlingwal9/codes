#include <bits/stdc++.h>
using namespace std;
class RobinKarp
{
private:
    int prime = 101;
    const int MOD = INT_MAX;

public:
    int generateHash(string s, int len)
    {
        int hash = 0;
        for (int i = 0; i < len; i++)
        {
            hash += ((pow(prime, i) % INT_MAX) * (s[i])) % INT_MAX;
        }
    }

} int main()
{
}