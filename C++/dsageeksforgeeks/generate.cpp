#include <bits/stdc++.h>
using namespace std;
typedef vector<string> Row;
typedef vector<Row> Matrix;
int insert(int zeros, int ones, int len)
{
    if (len == 0)
    {
        return 1;
    }
    if (len - zeros < 0 || len - ones < 0)
    {
        return 0;
    }
    int l = insert(zeros, ones, len - zeros);
    int r = insert(zeros, ones, len - ones);
    return l + r;
}
int main()
{
    cout << insert(1, 1, 3);
}