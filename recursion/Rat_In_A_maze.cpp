
#include<bits/stdc++.h>
using namespace std ;

class Solution {
  public:
    vector<string> result;
    vector<char> v={'D','R','U','L'};
    vector<vector<int>> movement={{1,0},{0,1},{-1,0},{0,-1}};
    void backtracking(vector<vector<int>> &mat,int i,int j,string s){
        int n=mat.size();
        if(i==n-1 && j==n-1){
            result.push_back(s);
            return;
        }
        if(i>=0 && i<n && j>=0 && j<n && mat[i][j]==1){
            mat[i][j]=0;
            for(int k=0;k<4;k++){
                s.push_back(v[k]);
                backtracking(mat,i+movement[k][0],j+movement[k][1],s);
                s.pop_back();
            }
            mat[i][j]=1;
        }
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        int n=mat.size();
        if (mat[0][0] == 0 || mat[n-1][n-1] == 0) return {}; 
        string s="";
        backtracking(mat,0,0,s);
        return result;
        
    }
};