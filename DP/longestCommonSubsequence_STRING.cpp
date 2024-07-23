/*
You are given strings s and t. Find one longest string that is a subsequence of both s and t.
A subsequence of a string x is the string obtained by removing zero or more characters from x and concatenating the remaining characters without changing the order.
*/

#include<bits/stdc++.h>
using namespace std ;
int dp[3005][3005];
int func(int i,int j,string & s1,string & s2){
        if(i<0 || j<0){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        int ans = 0;
        // Characters match
        if (s1[i] == s2[j]) {
            ans = func(i - 1, j - 1, s1, s2) + 1;
        } else {
            // Characters do not match
            ans = max(func(i - 1, j, s1, s2), func(i, j - 1, s1, s2));
        }
        return dp[i][j]=ans;
    }
string buildLCS(string &s1, string &s2) {
    int i = s1.size() - 1, j = s2.size() - 1;
    string lcs = "";
    while (i >= 0 && j >= 0) {                     // WHILE loop run O(s1.lenght+ s2.lenght) times
        if (s1[i] == s2[j]) {
            lcs += s1[i];
            i--; j--;
        } else if (i > 0 && dp[i-1][j] >= dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(lcs.begin(), lcs.end());           // TC of reverse function :=O(min(s1.lenght, s2.lenght))
    return lcs;
}

int main(){
    string s,t;
    cin >> s;
    cin >> t;
    memset(dp,-1,sizeof(dp));
    func(s.size()-1,t.size()-1,s,t);
    cout << buildLCS(s,t) << endl;

}