/*Given a string s, partition s such that every 
substring
 of the partition is a 
palindrome
. Return all possible palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool ispalidrome(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    vector<vector<string>> result;
    void func(string s,int index,vector<string>& v){
        if(index>=s.size()){
            result.push_back(v);
        }

        for(int j=index;j<=s.size();j++){
            if(ispalidrome(s,index,j) && s.substr(index,(j-index+1))!=""){
                v.push_back(s.substr(index,(j-index+1)));
                // Recur for the next part of the string
                func(s,j+1,v);
                // Backtrack: remove the last added palindrome to try the next possibility
                v.pop_back();
            }
        }

        
    }
    vector<vector<string>> partition(string s) {
        if(s=="") return result;
        vector<string> v;
        func(s,0,v);
        return result;
        
    }
};