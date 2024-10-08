#include<bits/stdc++.h>
using namespace std ;
int dp[310][5010];                            //we have to make a comibation if we use 1D dp we will get repeated sequence
int func(int index,int amount,vector <int>& coins ){
    if(amount==0){return 1;}
    if(index<0){return 0;}
    if(dp[index][amount]!=-1){return dp[index][amount];}
    int ways=0;
    for(int coin_amount=0;coin_amount<=amount;coin_amount+=coins[index]){
        if(amount-coin_amount>=0){
            ways+=func(index-1,amount-coin_amount,coins);
        }
    }
    return dp[index][amount]=ways;
}

int change(int amount, vector<int>& coins){
    memset(dp,-1,sizeof(dp));
    return func(coins.size()-1,amount,coins);

}
int main(){
    vector<int> coins={1,2,5};
    int amount=5;
    cout << change(amount,coins);
}