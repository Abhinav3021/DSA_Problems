#include<bits/stdc++.h>
using namespace std ;

int dp[205][20010];
    bool func(int index,int sum ,vector<int>& nums){
        if(sum==0){return true;}
        if(index<0){return false;}
        if(dp[index][sum]!=-1){return dp[index][sum];}
        //Don't choose the val
        bool ans=func(index-1,sum,nums);
        if(sum-nums[index]>=0){
            //Choose the value
            ans |=func(index-1,sum-nums[index],nums);
        }
        return dp[index][sum]=ans;
    }
    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int sum=0;
        for(auto i: nums){sum+=i;}
        if(sum %2!=0){return false;}
        sum=sum/2;
        return func(nums.size()-1,sum,nums); 
    }