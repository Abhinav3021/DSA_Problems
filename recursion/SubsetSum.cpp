#include<bits/stdc++.h>
using namespace std ;
int dp[1001][1001];
int func(vector<int> &a,int k,int i,int sum){
    if(sum==k){
        return 1;
    }
    if(i>=a.size() || sum>k){return 0;}
    if(dp[i][sum]!=-1){return dp[i][sum];}
    int ex=func(a,k,i+1,sum);
    int in=func(a,k,i+1,sum+a[i]);
    dp[i][sum]=ex || in;
    return ex || in;
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
  
    memset(dp,-1,sizeof(dp));
    return func(a,k,0,0)==1;
    // Write your code here
}