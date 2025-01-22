#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int belongs(int i, int j)
    {
        if (i < 3)
        {
            if (j < 3)
            {
                return 0;
            }
            else if (j < 6)
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
        else if (i < 6)
        {
            if (j < 3)
            {
                return 3;
            }
            else if (j < 6)
            {
                return 4;
            }
            else
            {
                return 5;
            }
        }
        else
        {
            if (j < 3)
            {
                return 6;
            }
            else if (j < 6)
            {
                return 7;
            }
            else
            {
                return 8;
            }
        }
        return -1;
    }
    bool canFill(vector<vector<char>> &board, vector<vector<int>> &box, int i,
                 int j, int bnum, int insert)
    {
        for (auto it : board[i])
        {
            if (it - '0' == insert)
            {
                return false;
            }
        }
        for (int it = 0; it < 9; it++)
        {
            if (board[i][it] - '0' == insert)
            {
                return false;
            }
        }
        if (box[bnum][insert - 1] == 1)
        {
            return false;
        }
        return true;
    }
    void solve(vector<vector<char>> &board, vector<vector<int>> &box, int i,
               int j)
    {
        if (i == 8 && j == 9)
        {
            return;
        }
        if (j == 9)
        {
            i = i + 1;
            j = 0;
        }
        if (board[i][j] == '.')
        {
            for (int k = 1; k <= 9; k++)
            {
                int boxn = belongs(i, j);
                if (canFill(board, box, i, j, boxn, k))
                {
                    board[i][j] = k + '0';
                    box[boxn][k - 1] = 1;
                    solve(board, box, i, j + 1);
                    board[i][j] = '.';
                    box[boxn][k - 1] = -1;
                }
            }
        }
        else
        {
            solve(board, box, i, j + 1);
        }
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        vector<vector<int>> box(9, vector<int>(9, -1));
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int curr = board[i][j] - '0';
                    if (i < 3)
                    {
                        if (j < 3)
                        {
                            box[0][curr - 1] = 1;
                        }
                        else if (j < 6)
                        {
                            box[1][curr - 1] = 1;
                        }
                        else
                        {
                            box[2][curr - 1] = 1;
                        }
                    }
                    else if (i < 6)
                    {
                        if (j < 3)
                        {
                            box[3][curr - 1] = 1;
                        }
                        else if (j < 6)
                        {
                            box[4][curr - 1] = 1;
                        }
                        else
                        {
                            box[5][curr - 1] = 1;
                        }
                    }
                    else
                    {
                        if (j < 3)
                        {
                            box[6][curr - 1] = 1;
                        }
                        else if (j < 6)
                        {
                            box[7][curr - 1] = 1;
                        }
                        else
                        {
                            box[8][curr - 1] = 1;
                        }
                    }
                }
            }
        }

        solve(board, box, 0, 0);
    }
};
int main()
{
    Solution s;
    vector<vector<char>> board{
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };
    s.solveSudoku(board);
}