#include <bits/stdc++.h>
#include "readinput.cpp"
using namespace std;
int getMax(vector<int>>& arr){
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++){
        maxi = max(arr[i], maxi);
    }
    return maxi; 
}
int countSort(vector<int>& arr )
{
    // code here
    int maxi = getMax(arr);
    vector<int> hash(maxi, 0);
    int n = arr.size();
    for (auto &it : arr)
    {

        hash[it]++;
    }

    for (int i = 1; i < hash.size(); i++)
    {

        hash[i] = hash[i - 1] + hash[i];
    }
    vector<int> ans(arr);
    for (int i = n - 1; i >= 0; i--)
    {

        int insertat = --hash[arr[i] - 'a'];
        ans[insertat] = arr[i];
    }

    return ans;
}
int main(){
    vector<int> arr = readInput();
    print(arr);
}