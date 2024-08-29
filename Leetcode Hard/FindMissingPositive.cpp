#include<bits/stdc++.h>
using namespace std ;

/*Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {  //Here we have to use the given vector as a hash table
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=0){nums[i]=n+2;}
        }
        for(int i=0;i<n;i++){
            if(abs(nums[i])<=n){
                if(nums[abs(nums[i])-1]>0) nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
                
        }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        return n+1;

    }
};