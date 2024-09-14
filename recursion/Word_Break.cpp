/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.
*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();
        vector<bool> dp(n + 1, false);  // DP array to store valid segmentations
        dp[0] = true;  // Base case: empty string can always be segmented

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // Check if s[0:j] is valid and s[j:i] exists in wordDict
                if (dp[j] && count(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) > 0) {
                    dp[i] = true;  // Mark current index as true if valid segmentation found
                    break;  // No need to check further
                }
            }
        }
        
        return dp[n];  // Return result for full string
    }
};




// ***********the normal recursive approach
// class Solution {
// public:
//     bool func(string s, vector<string>& wordDict,int i){
//         int n=s.size();
//         if(i>=s.size()){
//             return true;
//         }
//         for(int j=i+1;j<=n;j++){
//         if(count(wordDict.begin(),wordDict.end(),s.substr(i,j-i)) && func(s,wordDict,j)){
//             return true;
//         }
//         }
//         return false;
//     }
//     bool wordBreak(string s, vector<string>& wordDict) {
//         return func(s,wordDict,0);
//     }
// };