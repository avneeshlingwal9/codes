#include <bits/stdc++.h>
using namespace std;
int solve(int left, int right, char opr)
{
    if (opr == '|')
    {
        return left | right;
    }
    int ans = 0;
    switch (opr)
    {
    case '|':
        ans = left | right;
        break;
    case '&':
        ans = left & right;
        break;
    case '^':
        ans = left ^ right;
        break;
    }
    return ans;
}
bool evaluate(string s, int i, int j)
{

    int init = s[i] == 'T' ? 1 : 0;
    stack<int> st;
    st.push(init);
    while (i + 2 <= j)
    {
        int curr = st.top();
        st.pop();
        char opr = s[i + 1];
        int right = s[i + 2] == 'T' ? 1 : 0;
        st.push(solve(curr, right, opr));
        i += 2;
    }
    return st.top();
}
int main()
{
    string s = "T|F";
    cout << evaluate(s, 0, 2) << endl;
    cout << "correct " << (s[0] | s[2]) << endl;
}