/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 
*/

#include<bits/stdc++.h>
using namespace std ;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minheap;
        vector<int> v;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;   //making frequencies
        }
        for(auto p: m){
            minheap.push({p.second,p.first});      
            if(minheap.size()>k){minheap.pop();}
        }
        while(!minheap.empty()){
            v.push_back(minheap.top().second);
            minheap.pop();
        }
        return v;
    }
};