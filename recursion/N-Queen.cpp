/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

*/


#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> column;
    vector<int> positiveDiagonal;
    vector<int> negativeDiagonal;
    vector<vector<string>> result;  // Stores valid solutions
    vector<string> board;           // Each board is a vector of strings

    void backtracking(int r, int n) {
        if (r == n) {
            result.push_back(board);  // Push the current valid board configuration
            return;
        }

        for (int c = 0; c < n; c++) {
            if (column[c] == 1 || positiveDiagonal[c + r] == 1 || negativeDiagonal[r - c + n - 1] == 1) {
                continue;
            }

            // Place the queen
            column[c] = 1;
            positiveDiagonal[c + r] = 1;
            negativeDiagonal[r - c + n - 1] = 1;
            board[r][c] = 'Q';

            // Backtrack to the next row
            backtracking(r + 1, n);

            // Remove the queen and backtrack
            board[r][c] = '.';
            column[c] = 0;
            positiveDiagonal[c + r] = 0;
            negativeDiagonal[r - c + n - 1] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        // Initialize the board with n rows of strings, each containing n dots
        board = vector<string>(n, string(n, '.'));
        column.resize(n, 0);
        positiveDiagonal.resize(2 * n, 0);
        negativeDiagonal.resize(2 * n, 0);

        backtracking(0, n);
        return result;  // Return all the valid solutions
    }
};
