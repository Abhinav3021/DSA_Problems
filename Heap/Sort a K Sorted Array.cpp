/*
Given an array of n elements, where each element is at most k away from its target position, devise an algorithm that sorts in O(n log k) time. For example, let us consider k is 2, an element at index 7 in the sorted array, can be at indexes 5, 6, 7, 8, 9 in the given array.

Example:
Input : arr[] = {6, 5, 3, 2, 8, 10, 9}
k = 3 
Output : arr[] = {2, 3, 5, 6, 8, 9, 10} .
*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        int n=arr.size();
        priority_queue<int,vector<int>,greater<int>> minheap;
        int j=0;
        for(int i=0;i<n;i++){
            minheap.push(arr[i]);
            if(minheap.size()>k){
                arr[j]=minheap.top();
                minheap.pop();
                j++;
            }
            if(i==n-1){
                while(!minheap.empty()){
                    arr[j]=minheap.top();
                minheap.pop();
                j++;
                }
            }
        }
        
    }
};