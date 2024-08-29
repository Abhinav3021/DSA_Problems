/*
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<vector<int>> result;
    void func(vector<int>& candidates, int target,int i,vector<int> v){
        if(target==0){
            result.push_back(v);
            return ;
        }
        if(i>=candidates.size()) return ;
        if(target<0) return;
        // Case 1: Include the current candidate
        v.push_back(candidates[i]);
        func(candidates,target-candidates[i],i,v); // i is not incremented, allowing repetition
        v.pop_back();
        // Case 2: Exclude the current candidate and move to the next
        func(candidates,target,i+1,v);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        func(candidates,target,0,v);
        return result;
    }
};