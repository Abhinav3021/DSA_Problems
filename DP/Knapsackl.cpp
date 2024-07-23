#include<bits/stdc++.h>
using namespace std ;
long long val[110];
int wt[110];
long long dp[110][100010];      // here we have used the 2D dp because it is 0-1 kanpsack (we have to choose a element only once)

long long func(int index,int wt_left){
    if(wt_left==0){return 0;}
    if(index<0){
        return 0;
    }
    if(dp[index][wt_left]!=-1){return dp[index][wt_left];}
    //don't  choose the item at index
    long long ans=func(index-1,wt_left);
    // choose the item at index
    if(wt_left-wt[index]>=0){
        ans=max(ans,func(index-1,wt_left-wt[index])+val[index]);

    }
    return dp[index][wt_left]=ans;
}
                                           // O(N*w)
int main(){
  int n,w;
  cin >> n >> w;
  for(int i=0;i<n;i++){
    cin >> wt[i] >> val[i];
  }
  memset(dp,-1,sizeof(dp));
  cout<< func(n-1,w) << endl;
}