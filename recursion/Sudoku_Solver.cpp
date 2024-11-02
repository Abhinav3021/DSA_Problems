#include<bits/stdc++.h>
using namespace std ;



class Solution {
public:
    bool safty(vector<vector<char>>& board,int i,int j,char value){
        if(i<0 || i>=9 || j<0 || j>=9 ) return false;
        // for row and column verification
        for(int k=0;k<9;k++){
            if(value==board[k][j]){return false;}
            if(value==board[i][k]){return false;}
        }
        // 3x3 box
        int a=(i/3)*3,b=(j/3)*3;
        for(int x=a;x<a+3;x++){
            for(int y=b;y<b+3;y++){
                if(value==board[x][y]){
                    return false;
                }
            }
        }
        return true;
    }
    bool func(vector<vector<char>>& board,int i,int j){
        int n=board.size();
        int m=board[0].size();
        if(i==n){return true;}
        if(j==m){return func(board,i+1,0);}   //to change the row
                if(board[i][j]=='.'){
                    for(char k='1';k<='9';k++){
                        if(safty(board,i,j,k)){
                            board[i][j]=k;
                            if(func(board,i,j+1)){return true;}
                            board[i][j]='.'; //backtrack
                        }
                    }
                    return false;// no value is found
                }
                else{return func(board,i,j+1);}
    }
    void solveSudoku(vector<vector<char>>& board) {
        func(board,0,0);
    }
};