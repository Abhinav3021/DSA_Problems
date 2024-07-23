#include<bits/stdc++.h>
using namespace std ;
int dp[3005][3005];
int func(int i,int j,string & s1,string & s2){
        if(i<0 || j<0){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        // removing 1 ele from s1   
        int ans=func(i-1,j,s1,s2);
        // removing 1 ele from s2
        ans=max(ans,func(i,j-1,s1,s2));
        // removing 1 ele from s1 and s2
        ans=max(ans,func(i-1,j-1,s1,s2)+(s1[i]==s2[j]));
        return dp[i][j]=ans;
    }

int main(){
    string s,t;
    cin >> s;
    cin >> t;
    memset(dp,-1,sizeof(dp));
    int result=func(s.size()-1,t.size()-1,s,t);
    cout << result << endl;

}


//optimised
class Solution {
public:
    int dp[1005][1005];
    
    int func(int i, int j, string &s1, string &s2) {
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        // Characters match
        if (s1[i] == s2[j]) {
            ans = func(i - 1, j - 1, s1, s2) + 1;
        } else {
            // Characters do not match
            ans = max(func(i - 1, j, s1, s2), func(i, j - 1, s1, s2));
        }
        
        return dp[i][j] = ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        return func(text1.size() - 1, text2.size() - 1, text1, text2);
    }
};
