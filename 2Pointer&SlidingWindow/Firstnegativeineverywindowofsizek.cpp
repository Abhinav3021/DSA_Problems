#include<bits/stdc++.h>
using namespace std ;

vector<long long> printFirstNegativeInteger(long long int A[],
long long int N, long long int K) {
    deque<long long> v;
    vector<long long> result;
    int j = 0;

    for (int i = 0; i < N; i++) {
        // Add the current element to deque if it's negative
        if (A[i] < 0) {
            v.push_back(A[i]);
        }

        // Check if we have hit the window size of K
        if (i - j + 1 == K) {
            // If the deque is not empty, the front is the first negative
            if (!v.empty()) {
                result.push_back(v.front());
            } else {
                // If no negative number in the window, add 0
                result.push_back(0);
            }

            // Slide the window by moving the left pointer 'j'
            if (A[j] == v.front()) {
                v.pop_front();  // Remove the front of the deque if it was in the window
            }

            j++;  // Move the window's left edge
        }
    }

    // Return the result after processing all windows
    return result;
}
