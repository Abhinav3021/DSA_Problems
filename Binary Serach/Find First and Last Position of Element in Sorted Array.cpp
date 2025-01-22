/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
*/
#include<bits/stdc++.h>
using namespace std ;
class Solution {
public:
    int BinarySearchFirstOcc(vector<int>& nums, int target){
        int start=0,end=nums.size()-1,mid;
        int res=-1;
        while(start<=end){
            mid=start+(end-start)/2;
            if(nums[mid]==target){
                res=mid;
                end=mid-1;// Narrow the search to the left half
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return res;
    }
    int BinarySearchLastOcc(vector<int>& nums, int target){
        int start=0,end=nums.size()-1,mid;
        int res=-1;
        while(start<=end){
            mid=start+(end-start)/2;
            if(nums[mid]==target){
                res=mid;
                start=mid+1; // Narrow the search to the right half
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        v.push_back(BinarySearchFirstOcc(nums,target));
        v.push_back(BinarySearchLastOcc(nums,target));
        return v;
    }
};