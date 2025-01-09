/*
Given an array A[] of N positive integers and two positive integers K1 and K2.
Find the sum of all elements between K1th and K2th smallest elements of the array. It may be assumed that (1 <= k1 < k2 <= n).
*/
#include<bits/stdc++.h>
using namespace std ;

class Solution{
    public:
    int kthSmallest(long long arr[], long long n, long long k) {
        priority_queue<long long> maxheap;
        for(int i=0;i<n;i++){
            maxheap.push(arr[i]);
            if(maxheap.size()>k){maxheap.pop();}
        }
        return maxheap.top();
    }
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {

        long long sum=0;
        long long st=kthSmallest(A,N,K1);
        long long ed=kthSmallest(A,N,K2);
        for(int i=0;i<N;i++){
            if(A[i]>st && A[i]<ed){
                sum+=A[i];
            }
        }
        return sum;
    }
};