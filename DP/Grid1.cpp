#include<bits/stdc++.h>
using namespace std ;
int dp[1005][1005];
char grid[1005][1005];
vector <pair(int,int)> topoOrder;

int dfs(int i,int j){
    if()
    if(grid[i][j]=='#'){return 0;}
    dfs(i+1,j);
    dfs(i,j+1);
}




int main(){
    int H,W;
    cin >> H >> W;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
             cin >> grid[i][j];
        }
    }

}

