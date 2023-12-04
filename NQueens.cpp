#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> fNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);

        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }

        vector<int> leftRow(n, 0);
        vector<int> upperDiag(2 * n - 1, 0);
        vector<int> lowerDiag(2 * n - 1, 0);

        f(0, board, res, leftRow, upperDiag, lowerDiag, n);

        return res;
    }

    void f(int col, vector<string> &board, vector<vector<string>> &res,
               vector<int> &leftRow, vector<int> &upperDiag,
               vector<int> lowerDiag, int n)
    {

        if (col == n)
        {
            res.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {

            if (leftRow[row] == 0 &&
                upperDiag[row + col] == 0 &&
                lowerDiag[n - 1 + col - row] == 0)
            {

                board[row][col] = 'Q';

                leftRow[row] = 1;
                upperDiag[row + col] = 1;
                lowerDiag[n - 1 + col - row] = 1;

                f(col + 1, board, res, leftRow, upperDiag, lowerDiag, n);

                board[row][col] = '.';

                leftRow[row] = 0;
                upperDiag[row + col] = 0;
                lowerDiag[n - 1 + col - row] = 0;
            }
        }
    }
};
int main()
{

    return 0;
}