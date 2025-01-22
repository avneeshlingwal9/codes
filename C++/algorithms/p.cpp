//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int co(vector<int> &coins, int index, int sum, vector<int> &curr, vector<vector<int>> &ans)
    {
        if (sum == 0)
        {
            ans.push_back(curr);
            return 1;
        }
        if (index == coins.size())
        {
            return 0;
        }
        if (coins[index] > sum)
        {
            return co(coins, index + 1, sum, curr, ans);
        }

        int cou = co(coins, index + 1, sum, curr, ans);
        curr.push_back(coins[index]);
        cou += co(coins, index, sum - coins[index], curr, ans);
        curr.pop_back();
        return cou;
    }
    int count(vector<int> &coins, int sum)
    {
        // code here.
        vector<vector<int>> ans;
        vector<int> curr;

        int a = co(coins, 0, sum, curr, ans);
        return a;
    }
};

//{ Driver Code Starts.

int main()
{
    Solution s;
    vector<int> coins = {1, 2, 2};
    int sum = 4;
    s.count(coins, sum);
}

// } Driver Code Ends