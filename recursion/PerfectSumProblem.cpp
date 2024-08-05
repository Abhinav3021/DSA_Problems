/*
Given an array arr of size n of non-negative integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

Note: Answer can be very large, so, output answer modulo 109+7.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
    int const M=1e9+7;
    int count;
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

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends