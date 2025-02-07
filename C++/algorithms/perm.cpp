#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void generate_permutations(vector<int> &arr, vector<vector<int>> &ans, int index = 0)
{
    if (index == arr.size())
    {
        ans.push_back(arr);
        return;
    }
    unordered_set<int> done;

    for (int i = index; i < arr.size(); i++)
    {

        swap(arr[i], arr[index]);
        generate_permutations(arr, ans, index + 1);
        swap(arr[i], arr[index]);
    }
}
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    vector<vector<int>> ans;
    generate_permutations(arr, ans, 0);
    for (auto i : ans)
    {
        print(i);
    }
}