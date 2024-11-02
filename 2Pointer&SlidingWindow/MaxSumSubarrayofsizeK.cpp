#include<bits/stdc++.h>
using namespace std ;

class Solution{     
public:
    long maximumSumSubarray(int K, vector<int> &Arr, int N) {
        if (N < K) {
            return 0;  // Handle case where array is smaller than window
        }
        long sum = 0;
        
        // Calculate sum of first window
        for (int i = 0; i < K; i++) {
            sum += Arr[i];
        }
        long maxSum = sum;
        // Slide the window
        for (int i = K; i < N; i++) {
            sum = sum - Arr[i - K] + Arr[i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};