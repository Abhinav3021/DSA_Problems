/*
Given an array arr of size n of non-negative integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

Note: Answer can be very large, so, output answer modulo 109+7.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*
class Solution{

	public:
    int const M=1e9+7;
    int count;                                                 TC:O(2**n)
                                                               SC:O(n) because we are using arr in SubsetSum which is called by reference so the worst it can go is n
    void SubsetSum(int arr[],int n,int i,int sum,int s){
        if(s==sum){
           count++;
           return;
        }
        if(s>sum || i>=n){return ;}
        if(i<n){
        SubsetSum(arr,n,i,sum,s);     
        s+=arr[i];
        SubsetSum(arr,n,i+1,sum,s);
    }
    }
	int perfectSum(int arr[], int n, int sum)
	{
        count=0;
        int s=0;
        int n = sizeof(arr) / sizeof(arr[0]);
        SubsetSum(arr,n,0,sum,s);
        return count;
	}
	  
};
*/

//{ Driver Code Starts.

int mod = (int)(1e9 + 7); // Initialize mod value for calculations
    vector<vector<int>> dp; // 2D vector to store dynamic programming values
    int N; // Size of the array

    int fun(int pos, int sum, int arr[]) {
        if (pos >= N)
            return sum == 0; // Check if sum is zero when array position reaches end

        int &ans = dp[pos][sum]; // Reference to store calculated value in dp vector
        if (ans != -1)
            return ans; // Return the already calculated value from dp vector

        ans = 0; // Initialize answer with zero

        ans += fun(pos + 1, sum, arr); // Recursively call function for next position with sum unchanged
        ans %= mod; // Take modulo of the answer to avoid overflow
        if (arr[pos] <= sum)
            ans += fun(pos + 1, sum - arr[pos], arr), ans %= mod; // Recursively call function for next position with reduced sum

        return ans; // Return the calculated answer
           
    }

    public:
    int perfectSum(int arr[], int n, int sum)
    {
        dp.assign(n + 1, vector<int> (sum + 2, -1)); // Initialize dp vector with -1
        N = n; // Assign n to N variable
        
        return fun(0, sum, arr); // Call recursive function with initial parameters
    }
	  

// } Driver Code Ends