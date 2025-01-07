
/*
Question Link:- https://leetcode.com/problems/count-paths-with-the-given-xor-value/description/
*/

class Solution {
public:
    const int mod = 1e9 + 7;
    unordered_map<long long,int> memo;

    int solve(vector<vector<int>>& grid, int k, int i, int j, int curr_xor) {
        int n = grid.size();
        int m = grid[0].size();

        // Base case: if we reach the bottom-right corner
        if (i == n - 1 && j == m - 1) {
            return ((curr_xor ^ grid[i][j]) == k) ? 1 : 0;
        }
        if (i >= n || j >= m) {
            return 0;
        }
        // Create a unique key for memoization
        long long key = ((long long)i << 40) | ((long long)j << 20) | curr_xor;
        if (memo.count(key)) {
            return memo[key];
        }

        int down = solve(grid, k, i + 1, j, curr_xor ^ grid[i][j]);
        int right = solve(grid, k, i, j + 1, curr_xor ^ grid[i][j]);

        memo[key] = (down + right) % mod;

        return memo[key];
    }

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        return solve(grid, k, 0, 0, 0);
    }
};
