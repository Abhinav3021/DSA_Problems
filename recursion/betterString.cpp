//Given a pair of strings of equal lengths, Geek wants to find the better string. The better string is the string having more number of distinct subsequences.
//If both the strings have equal count of distinct subsequence then return str1.



#include<bits/stdc++.h>
using namespace std ;
class Solution {
  public:
    const int MOD=1e9+7;
    int countSub(string str){
        vector<int> last(26,-1);
        int n=str.size();
        int dp[n+1];
        dp[0]=1;  // as empty string is having one sequence
        for (int i = 1; i <= n; i++) {
            dp[i] = (2 * dp[i - 1]) % MOD;
            if (last[str[i - 1] - 'a'] != -1) {
                dp[i] = (dp[i] - dp[last[str[i - 1] - 'a']] + MOD) % MOD;
            }
            last[str[i - 1] - 'a'] = i - 1;
        }
        return dp[n];
        
            
    }
    string betterString(string str1, string str2) {
        // code here
        int a=countSub(str1);
        int b=countSub(str2);
        if(a<b) return str2;
        return str1;
        
        
        
    }
};