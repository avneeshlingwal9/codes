#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        /*
        So, the array is divided into A[0.. i - 1] as 0 , A[i .. j - 1] as 1 and A[j  .. k -1] as unprocessed as A[k .. n] as 2.


        */
        int i = 0, j = 0, k = nums.size() - 1;
        while (j <= k)
        {
            if (nums[k] == 2)
            {
                k--;
            }
            else if (nums[k] == 1)
            {
                swap(nums[k], nums[j]);
                j++;
            }
            else
            {
                swap(nums[k], nums[i]);
                i++;
                if (j < i)
                {
                    j = i;
                }
            }
        }
    }
};
int main()
{
    Solution s;
    vector<int> nums = {0, 0};
    s.sortColors(nums);
}