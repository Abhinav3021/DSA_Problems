/*
Given a rod of length N inches and an array of prices, price[]. price[i] denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Note: Consider 1-based indexing.
Input:
N = 8
Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
Output:
22
Explanation:
The maximum obtainable value is 22 by 
cutting in two pieces of lengths 2 and 
6, i.e., 5+17=22.
*/
#include<bits/stdc++.h>
using namespace std ;
int dp[1010];
int func(int n, vector<int>& price){
    if(n==0){return 0;}
    if(dp[n]!=-1){return dp[n];}
    int ans=0;
    for(int i=0;i<price.size();i++){
        if(n-(i+1)>=0){
        ans=max(ans,func(n-(i+1),price)+price[i]);
    }
    }
    return dp[n]=ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    vector<int> v={3, 5, 8, 9, 10, 17, 17, 20};
    int n=8;
    cout << func(n,v);
}