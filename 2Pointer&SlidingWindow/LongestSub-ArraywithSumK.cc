/*
Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. It is guaranteed that a valid subarray exists.
*/

#include<bits/stdc++.h>
using namespace std ;

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Create an unordered_map to store the prefix sums and their indices
        unordered_map<int, int> prefixSumMap;
        int sum = 0; // Initialize the sum of elements
        int maxlen = 0; // Initialize the maximum length of subarray

        for (int i = 0; i < N; i++) {
            sum += A[i]; // Update the sum

            // If the sum is equal to K, update maxlen
            if (sum == K) {
                maxlen = i + 1;
            }

            // If (sum - K) exists in the map, update maxlen
            if (prefixSumMap.find(sum - K) != prefixSumMap.end()) {
                maxlen = max(maxlen, i - prefixSumMap[sum - K]);
            }

            // If sum is not already in the map, add it
            if (prefixSumMap.find(sum) == prefixSumMap.end()) {
                prefixSumMap[sum] = i;
            }
        }

        return maxlen;
    }
};