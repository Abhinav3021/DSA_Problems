/*
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.


Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        int result = INT_MAX, i = 0, j = 0, I = 0, J = 0;

        // Populate the frequency map with characters in t
        for(int i = 0; i < t.size(); i++) {
            m[t[i]]++;
        }
        
        int count = m.size(); // Number of unique characters needed
        if(t.size() > s.size()) return ""; // Early exit if t is longer than s

        // Expand the window by moving the right pointer (j)
        while(j < s.size()) {
            if(count != 0 && m.find(s[j]) != m.end()) { // Check if s[j] is in t
                m[s[j]]--;
                if(m[s[j]] == 0) count--; // Fully matched a character in t
            }
            
            // Try to shrink the window from the left (i) when all characters are matched
            while(count == 0) {
                // Update the minimum window if a smaller valid window is found
                if(result > (j - i + 1)) {
                    result = j - i + 1;
                    J = j;
                    I = i;
                }
                
                // Remove character at left pointer and move i to shrink the window
                if(m.find(s[i]) != m.end()) {
                    if(m[s[i]] == 0) count++; // Lose a match if frequency goes above zero
                    m[s[i]]++;
                }
                i++;
            }
            j++;
        }

        // Return the minimum window substring, or empty string if no valid window was found
        return result == INT_MAX ? "" : s.substr(I, J - I + 1);
    }
};
