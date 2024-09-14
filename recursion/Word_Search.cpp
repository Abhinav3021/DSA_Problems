/*Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.


 */


#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int N,M;
    vector<vector<bool>> visited;
    bool dfs(vector<vector<char>>& board, string word,int i,int j,int index){
        if(index==word.size()){return true;}
        if(i<0 || i>=N || j<0 || j>=M || board[i][j]!=word[index] || visited[i][j]){
            return false;
        }
        visited[i][j]=true;
        // Explore all four possible directions (up, down, left, right)
        bool found=dfs(board,word,i-1,j,index+1)||
                   dfs(board,word,i+1,j,index+1) ||
                   dfs(board,word,i,j-1,index+1) ||
                   dfs(board,word,i,j+1,index+1);
        visited[i][j]=false; //backtraking: unmark the cell when it reached the wrong value
        return found;        
    }
    bool exist(vector<vector<char>>& board, string word) {
        N=board.size();
        M=board[0].size();
        visited=vector<vector<bool>>(N,vector<bool>(M,false));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                // Start DFS if the first character matches
                if(board[i][j]==word[0] && dfs(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};