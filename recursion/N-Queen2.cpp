/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle

Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> column;
    vector<int> positiveDiagonal;
    vector<int> negativeDiagonal;
    int c;
    void backtracking(int r, int n) {
        if (r == n) {
            c++;  // Push the current valid board configuration
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
       

            // Backtrack to the next row
            backtracking(r + 1, n);

            // Remove the queen and backtrack
            
            column[c] = 0;
            positiveDiagonal[c + r] = 0;
            negativeDiagonal[r - c + n - 1] = 0;
        }
    }

    int totalNQueens(int n) {
        // Initialize the board with n rows of strings, each containing n dots
        c=0;
        column.resize(n, 0);
        positiveDiagonal.resize(2 * n, 0);
        negativeDiagonal.resize(2 * n, 0);

        backtracking(0, n);
        return c;  // Return all the valid solutions
    }
};

    
