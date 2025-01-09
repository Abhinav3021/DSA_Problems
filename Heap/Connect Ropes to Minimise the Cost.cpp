/*
Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost.
The cost to connect two ropes is the sum of their lengths. 
*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>> minheap;
        int cost=0;
        for(int i=0;i<arr.size();i++){
            minheap.push(arr[i]);
        }
        while(minheap.size()>1){
            int a=minheap.top(); minheap.pop();
            int b=minheap.top(); minheap.pop();
            cost+=a+b;
            minheap.push(a+b);
        }
        return cost;
    }
};