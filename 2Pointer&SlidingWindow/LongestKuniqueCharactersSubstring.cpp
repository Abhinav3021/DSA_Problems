/*
Given a string s, you need to print the size of the longest possible substring with exactly k unique characters. If no possible substring exists, print -1.

Examples:

Input:
s = "aabacbebebe", k = 3
Output: 7
Explanation: 
"cbebebe" is the longest substring with 3 distinct characters.
*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int longestKSubstr(string s, int k) {
        unordered_map<char, int> m;  // Use char instead of int as key
        int result = -1, i = 0, j = 0;

        while (j < s.size()) {
            // Add the current character to the map
            m[s[j]]++;

            // Check if we have exactly k unique characters
            if (m.size() == k) {
                result = max(result, j - i + 1);  // Update the maximum length
            }

            // If the map size exceeds k, reduce the window from the left
            while (m.size() > k) {
                m[s[i]]--;
                if (m[s[i]] == 0) {
                    m.erase(s[i]);
                }
                i++;  // Move the left pointer
            }
            
            j++;  // Move the right pointer
        }
        
        return result;
    }
};

