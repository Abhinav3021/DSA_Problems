/*
You are given an array arr[] of integers, where each element arr[i] represents the number of pages in the ith book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

Examples:

Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
[12] and [34, 67, 90] Maximum Pages = 191
[12, 34] and [67, 90] Maximum Pages = 157
[12, 34, 67] and [90] Maximum Pages = 113.
Therefore, the minimum of these cases is 113, which is selected as the output.

Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Allocation can not be done.

Input: arr[] = [22, 23, 67], k = 1
Output: 112
*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
  public:
    // Check if allocation is possible with max pages `mx`
    bool isValid(vector<int> &arr, int n, int k, int mx) {
        int student = 1, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum > mx) {  // Allocate to a new student
                student++;
                sum = arr[i];
            }
            if (student > k) return false;  // Too many students needed
        }
        return true;
    }

    // Find the minimum pages that can be allocated
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) return -1;  // More students than books

        int start = 0, end = 0, mid, result;
        for (int i = 0; i < n; i++) {
            end += arr[i];          // Sum of all pages
            start = max(start, arr[i]);  // Max single book pages
        }

        // Binary search for the optimal solution
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (isValid(arr, n, k, mid)) {
                result = mid;  // Update result and search left
                end = mid - 1;
            } else {
                start = mid + 1;  // Search right
            }
        }
        return result;
    }
};
