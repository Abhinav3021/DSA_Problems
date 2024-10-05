#include<bits/stdc++.h>
using namespace std ;
const int Mod=1e9+7;
int dp[1005][1005];
char grid[1005][1005];
//int count=0;

int func(int i,int j,int H,int W,int &count){
    //base condition
    if(i==H-1 && j==W-1){
        count++;
        dp[i][j]=count;
        return count;
    }
    if(dp[i][j]!=-1){return dp[i][j];}
    if(i>H-1 || j>W-1 || i<0 || j<0 || grid[i][j]=='#') return 0;
    func(i+1,j,H,W,count);
    func(i,j+1,H,W,count);
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
    int count=0;
    func(0,0,H,W,count);
    cout << count << '\n';
    return count;

}

