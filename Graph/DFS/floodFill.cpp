/*
You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.

 

Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

Output: [[2,2,2],[2,2,0],[2,0,1]]

Explanation:



From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.

Note the bottom corner is not colored 2, because it is not horizontally or vertically connected to the starting pixel.
*/


#include<bits/stdc++.h>
using namespace std ;


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // DFS function to perform flood fill
    // Parameters:
    // i, j: current position in image
    // image: input image to be modified
    // newcolor: color to fill with
    // currentColor: original color of the starting pixel
    void dfs(int i, int j, vector<vector<int>>& image, int newcolor, int currentColor) {
        int n = image.size();
        int m = image[0].size();
        
        // Base cases: return if indices are out of bounds
        if(i < 0 || j < 0) { return; }
        if(i >= n || j >= m) { return; }
        
        // Return if current pixel is not the same as starting pixel's color
        if(image[i][j] != currentColor) { return; }
        
        // Fill current pixel with new color
        image[i][j] = newcolor;

        // Recursively fill all 4 adjacent pixels (up, down, right, left)
        dfs(i-1, j, image, newcolor, currentColor);  // Up
        dfs(i+1, j, image, newcolor, currentColor);  // Down
        dfs(i, j+1, image, newcolor, currentColor);  // Right
        dfs(i, j-1, image, newcolor, currentColor);  // Left
    }
    
    // Main function to perform flood fill
    // Parameters:
    // image: input image
    // sr, sc: starting row and column
    // color: new color to fill with
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // Only perform flood fill if starting pixel is different from new color
        // This check prevents infinite recursion when start pixel color equals new color
        if(image[sr][sc] != color) {
            dfs(sr, sc, image, color, image[sr][sc]);
        }
        return image;
    }
};