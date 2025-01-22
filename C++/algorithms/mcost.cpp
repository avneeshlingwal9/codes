#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    unordered_map<int, pair<int, int>> mp{
        {1, {0, 1}},
        {2, {0, -1}},
        {3, {1, 0}},
        {4, {-1, 0}}

    };
    bool canGo(vector<vector<int>> &grid, int i, int j)
    {
        return !(i == -1 || i == grid.size() || j == -1 || j == grid[0].size());
    }
    void solve(vector<vector<int>> &grid, int &ans, int &curr, int i, int j)
    {
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
        {
            ans = min(curr, ans);
            return;
        }

        for (int k = 1; k <= 4; k++)
        {
            // Original Direction

            if (k == grid[i][j])
            {
                int new_i = i + mp[k].first;
                int new_j = j + mp[k].second;
                if (canGo(grid, new_i, new_j))
                {
                    solve(grid, ans, curr, new_i, new_j);
                }
            }
            else
            {
                int new_i = i + mp[k].first;
                int new_j = j + mp[k].second;
                if (canGo(grid, new_i, new_j))
                {
                    curr++;
                    solve(grid, ans, curr, new_i, new_j);
                    curr--;
                }
            }
        }
    }
    int minCost(vector<vector<int>> &grid)
    {
        int curr{0}, ans{0};
        solve(grid, ans, curr, 0, 0);
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> a{
        {{1, 1, 1, 1},
         {2, 2, 2, 2},
         {1, 1, 1, 1},
         {2, 2, 2, 2}}};
    cout << s.minCost(a);
}