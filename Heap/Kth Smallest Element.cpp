/*
Given an array arr[] and an integer k where k is smaller than the size of the array, the task is to find the kth smallest element in the given array.

Follow up: Don't solve it using the inbuilt sort function.

Examples :

Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
Output:  7
Explanation: 3rd smallest element in the given array is 7.
Input: arr[] = [2, 3, 1, 20, 15], k = 4 
Output: 15
Explanation: 4th smallest element in the given array is 15.
*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> maxheap;
        for(int i=0;i<arr.size();i++){
            maxheap.push(arr[i]);
            if(maxheap.size()>k){maxheap.pop();}
        }
        return maxheap.top();
    }
};
//TC:O(n.log(k))
// as Each insertion (maxheap.push) or deletion (maxheap.pop) operation takes O(logk), where k is the size of the heap.