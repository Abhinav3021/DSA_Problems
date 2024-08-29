#include<bits/stdc++.h>
using namespace std ;class Solution {
public:
    int func(string s,int index,vector<int> dp){
        if(index==s.length()) return 1; // successfull traverse the string 
        if(s[index]=='0'){return 0;}
        if(dp[index]!=-1){return dp[index];}
        int ways=func(s,index+1,dp); // travel through one -one step
        if(index+1<s.length() && (s[index]=='1' || (s[index]=='2' && s[index+1]<='6'))){
            ways+=func(s,index+2,dp);  // travel through two steps
        }
        dp[index]=ways;
        return ways;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        return func(s,0,dp);
        
        
    }
};
