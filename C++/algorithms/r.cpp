//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    const int MOD = INT_MAX;
    int prime = 101;

public:
    int generateHash(string s, int len)
    {
        int hash = 0;
        for (int i = 0; i < len; i++)
        {
            hash += ((pow(prime, i) % MOD) * s[i]) % MOD;
        }
        return hash;
    }
    void reHash(string s, int old, int new_in, int &prevHash, int m)
    {
        prevHash -= s[old];
        prevHash /= prime;
        prevHash += (((pow(prime, m - 1)) % MOD) * s[new_in]) % MOD;
    }
    bool check(string p, string s, int start)
    {
        for (int i = 0; i < p.length(); i++)
        {
            if (s[start + i] != p[i])
            {
                return false;
            }
        }
        return true;
    }

    vector<int> search(string pattern, string text)
    {
        int hash = generateHash(pattern, p.size());
        int thash = generateHash(text, p.size());
        vector<int> ans;
        int n = text.size();
        int m = pattern.size();
        for (int i = 0; i < n - m + 1; i++)
        {
            if (thash == hash && check(pattern, text, i))
            {
                ans.push_back(i + 1);
            }
            reHash(text, i, i + m, thash, m);
        }
        return ans;
        // code here.
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        for (int i : res)
            cout << i << " ";
        cout << endl;

        cout << "~" << "\n";
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends