#include <bits/stdc++.h>
using namespace std;
long long calculateScore(string s)
{
    string alphabets = "abcdefghijklmnopqrstuvwxyz";

    map<char, vector<int>> mp;
    long long score = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int currIndex = s[i] - 'a';
        char mirror = alphabets[25 - currIndex];
        if (mp[mirror].size() != 0)
        {
            score += (i - mp[mirror].back());
            mp[mirror].pop_back();
        }
        else
        {
            mp[s[i]].push_back(i);
        }
    }
    return score;
}
int main()
{
    calculateScore("aczzx");
}