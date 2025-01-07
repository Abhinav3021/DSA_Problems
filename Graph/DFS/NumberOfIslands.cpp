/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
*/


#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    // DFS function to mark all connected '1's as visited by changing them to '0'
    void dfs(int i, int j, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Base cases: return if indices are out of bounds
        if(i < 0 || j < 0) { return; }
        if(i >= n || j >= m) { return; }
        
        // Return if current cell is water ('0')
        if(grid[i][j] == '0') {
            return;
        }
        
        // Mark current cell as visited by changing it to '0'
        grid[i][j] = '0';
        
        // Recursively visit all 4 adjacent cells (up, down, left, right)
        dfs(i-1, j, grid);  // Up
        dfs(i+1, j, grid);  // Down
        dfs(i, j-1, grid);  // Left
        dfs(i, j+1, grid);  // Right
    }
    
    // Function to count number of islands in the grid
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;  // Counter for number of islands
        
        // Iterate through each cell in the grid
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // If we find a land cell ('1'), it's a new island
                if(grid[i][j] == '1') {
                    dfs(i, j, grid);  // Mark all connected land cells as visited
                    count++;  // Increment island count
                }
            }
        }
        return count;
    }
};