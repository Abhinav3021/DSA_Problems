
/*
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array.
The result should also be sorted in ascending order.

Example 1:
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

Example 2:
Input: arr = [1,1,2,3,4,5], k = 4, x = -1
Output: [1,1,2,3]

*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> maxheap;
        vector<int> v;
        for(int i=0;i<arr.size();i++){
            maxheap.push({abs(x - arr[i]), arr[i]});
            if(maxheap.size()>k){
                maxheap.pop();
            }
        }
        while(!maxheap.empty()){
            v.push_back(maxheap.top().second);
            maxheap.pop();
        }
        sort(v.begin(),v.end());
        return v;
    }
};