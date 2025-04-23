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

int sign(int a) { return a > 0 ? 1 : -1; }
vector<int> asteroidCollision(vector<int> &asteroids)
{
    vector<int> ans;
    for (int i = 0; i < asteroids.size(); i++)
    {
        if (ans.empty())
        {
            ans.push_back(asteroids[i]);
        }
        else
        {
            if ((ans.back() > 0 && asteroids[i] > 0) ||
                (ans.back() < 0 && asteroids[i] < 0) || (ans.back() < 0 && asteroids[i] > 0))
            {
                ans.push_back(asteroids[i]);
            }
            // Case 1 same sign

            // Sign is different
            else
            {
                // If both are same

                while (!ans.empty() &&
                       abs(ans.back()) < abs(asteroids[i]))
                {
                    ans.pop_back();
                }
                if (ans.empty())
                {
                    ans.push_back(asteroids[i]);
                }
                else
                {
                    if (abs(ans.back()) == abs(asteroids[i]))
                    {

                        ans.pop_back();
                    }
                    else if (abs(ans.back()) < abs(asteroids[i]))
                    {

                        ans.push_back(asteroids[i]);
                    }
                }
            }
        }
    }
    return ans;
}
void temp()
{
    vector<int> arr{7, 5, 8, 5};
    int n = arr.size();
    vector<int> nsl(n, 0), nsr(n, 0);
    stack<int> st;
    for (int i = 0; i < arr.size(); i++)
    {
        if (st.empty())
        {
            nsl[i] = -1;
        }
        else
        {
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                nsl[i] = -1;
            }
            else
            {
                nsl[i] = st.top();
            }
        }
        // Everyone in the stack is greater than ith element.
        st.push(i);
    }
    while (!st.empty())
    {
        st.pop();
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            nsr[i] = n;
        }
        else
        {
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                nsr[i] = n;
            }
            else
            {
                nsr[i] = st.top();
            }
        }
        st.push(i);
    }
}
long long subarrayMax(vector<int> &nums)
{
    int n = nums.size();
    vector<int> nme(n, 0);
    vector<int> pmee(n, 0);
    stack<int> st;
    // First calculate the pmee,
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            st.push(nums[i]);
            pmee[i] = -1; // No previously small element exist.
        }
        else
        {
            // Till we don't find an element greater than our current element we keep searching on the left.
            while (!st.empty() && nums[st.top()] <= nums[i])
            {
                st.pop();
            }
            pmee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    while (!st.empty())
    {
        st.pop();
    }
    // Calcuating nme
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            st.push(nums[i]);
            nme[i] = n;
        }
        else
        {
            // Till we don't come across a smaller element on the right, we keep popping.
            while (!st.empty() && nums[st.top()] < nums[i])
            {
                st.pop();
            }
            nme[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        long long curr = (i - pmee[i]) * (nme[i] - i);

        ans += (curr * nums[i]);
    }
    return ans;
}
struct pa
{
    int l;
    int k;
};

int main()

{
    map<pa, bool> m;
}