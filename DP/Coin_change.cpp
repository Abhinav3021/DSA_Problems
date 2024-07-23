#include<bits/stdc++.h>
using namespace std ;
int dp[10010];
    long long func(int amount,vector<int>& coins){
        if (amount==0){return 0;}
        if(dp[amount]!=-1){return dp[amount];}
        int ans=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(amount-coins[i]>=0){
            ans=min(ans +0LL,func(amount-coins[i],coins)+ 1LL);
        }
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans=func(amount,coins);
        return (ans == INT_MAX) ? -1 : ans;
        
    }
    int main(){
        vector<int> v={1,2,5};
        int amount=11;
        int result= coinChange(v,amount);
        cout << result << endl;
    }