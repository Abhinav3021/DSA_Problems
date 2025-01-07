/*
Given a 2D integer matrix mat[][] of size n x m, where every row and column is sorted in increasing order and a number x, the task is to find whether element x is present in the matrix.

*/

class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
        int target=x;
        int n=mat.size();
        int m=mat[0].size();
        int i=0,j=m-1; // we start from the top right corner 
        while(i>=0 && i<n && j>=0 && j<m){
            if(mat[i][j]==target){return true;}
            else if(mat[i][j]>target){j--;}
            else if(mat[i][j]<target){i++;}
        }
        return false;  // element not found
    }
    
};