/*
Given an array of integers A.  There is a sliding window of size B which 

is moving from the very left of the array to the very right. 

You can only see the w numbers in the window. Each time the sliding window moves 

rightwards by one position. You have to find the maximum for each window. 

The following example will give you more clarity.

The array A is [1 3 -1 -3 5 3 6 7], and B is 3.
*/

#include<bits/stdc++.h>
using namespace std ;

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    // If the window size B is greater than or equal to the size of the array,
    // return the maximum element of the entire array.
    if (B >= A.size()) {
        return { *max_element(A.begin(), A.end()) };
    }

    deque<int> dq; // Deque to store elements of the current window
    vector<int> c; // Vector to store the maximums of each window

    // Initialize the deque with the first window of size B
    for (int i = 0; i < B; i++) {
        // Remove elements from the back if they are smaller than the current element A[i]
        while (!dq.empty() && dq.back() < A[i]) {
            dq.pop_back();
        }
        dq.push_back(A[i]); // Add the current element to the deque
    }

    // Process the rest of the elements, starting from A[B] to A[n-1]
    for (int i = B; i < A.size(); i++) {
        // Add the front element of deque (max of the previous window) to result
        c.push_back(dq.front());

        // Remove the element going out of the window from the front of deque
        if (!dq.empty() && dq.front() == A[i - B]) {
            dq.pop_front();
        }

        // Remove elements from the back if they are smaller than the current element A[i]
        while (!dq.empty() && dq.back() < A[i]) {
            dq.pop_back();
        }
        dq.push_back(A[i]); // Add the current element to the deque
    }

    // Add the maximum of the last window
    c.push_back(dq.front());

    return c; // Return the result containing max of each sliding window
}
