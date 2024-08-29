
/*
Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 
*/
#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;  // To store all the unique subsets
        vector<int> subset;          // To store the current subset
        
        // Sort the array to make it easier to skip duplicates
        sort(nums.begin(), nums.end());
        
        // Start backtracking
        backtrack(nums, result, subset, 0);
        
        return result;
    }
    
private:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& subset, int start) {
        // Add the current subset to the result
        result.push_back(subset);
        
        // Explore further subsets
        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates
            if (i != start && nums[i] == nums[i - 1]) continue;
            
            // Include nums[i] in the current subset
            subset.push_back(nums[i]);
            
            // Move to the next element
            backtrack(nums, result, subset, i + 1);
            
            // Backtrack, remove the last element added
            subset.pop_back();
        }
    }
};
