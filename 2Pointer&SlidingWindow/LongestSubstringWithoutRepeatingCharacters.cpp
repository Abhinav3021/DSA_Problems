#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_set<int> set;
       int c=0;
       int left=0,right=0;
       while(right<s.size()){
            if(set.find(s[right])==set.end()){
                set.insert(s[right]);
                c=max(c,right-left+1);
                right++;
            }
            else{
                set.erase(s[left]);
                left++;
            }
        
       }
       return c;
    }
};