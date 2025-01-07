/*
The stock span problem is a financial problem where we have a series of daily price quotes for a stock denoted by an array arr[] and the task is to calculate the span of the stock’s price for all days. The span arr[i] of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the given day is less than or equal to its price on the current day.

Examples:

Input: arr[] = [100, 80, 60, 70, 60, 75, 85]
Output: [1, 1, 1, 2, 1, 4, 6]
Explanation: Traversing the given input span 100 is greater than equal to 100 and there are no more elements behind it so the span is 1, 80 is greater than equal to 80 and smaller than 100 so the span is 1, 60 is greater than equal to 60 and smaller than 80 so the span is 1, 70 is greater than equal to 60,70 and smaller than 80 so the span is 2 and so on.  Hence the output will be 1 1 1 2 1 4 6.


*/

 class Solution {
  public:
    // Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        stack<int>s;
        vector<int> v;
        int n=arr.size();
        for(int i=0;i<n;i++){
                    while(!s.empty() && arr[s.top()]<=arr[i]){
                        s.pop();
                    }
                    if(s.empty()){v.push_back(i+1);}
                    else{
                        v.push_back(i-s.top());
                    }
                    s.push(i);
        }
        return v;
    }
};