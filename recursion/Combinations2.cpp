/*
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 
*/


#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<vector<int>> result;

    void func(vector<int>& candidates, int target, int i, vector<int>& v) {
        if (target == 0) {
            result.push_back(v);
            return;
        }
        for (int j = i; j < candidates.size(); ++j) {
            if (j > i && candidates[j] == candidates[j - 1]) continue; // Skip duplicates

            if (candidates[j] > target) break; // No need to continue if the candidate is greater than the target

            v.push_back(candidates[j]);
            func(candidates, target - candidates[j], j + 1, v); // Move to the next index for the next call
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        func(candidates, target, 0, v);
        return result;
    }
};
