#include<bits/stdc++.h>
using namespace std ;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> m;  // Map to store the frequency of each character in the current window
        int result = 0, i = 0, j = 0;  // Initialize result to store max length, i and j for window boundaries

        // Start expanding the window with j
        while (j < s.size()) {
            m[s[j]]++;  // Add current character to the map and update its frequency
            
            // If window size equals map size, all characters are unique
            if (m.size() == (j - i + 1)) {
                result = max(result, (j - i + 1));  // Update the result if current window length is greater
            }
            
            // If map size is smaller than window size, there are duplicate characters
            if (m.size() < (j - i + 1)) {
                // Shrink the window from the left until all characters are unique
                while (m.size() < (j - i + 1)) {
                    m[s[i]]--;  // Decrement frequency of the character at the left of the window
                    if (m[s[i]] == 0) {  // If frequency becomes zero, remove it from the map
                        m.erase(s[i]);
                    }
                    i++;  // Move the left boundary of the window to the right
                }
            }
            j++;  // Expand the window to the right by moving j
        }
        
        return result;  // Return the length of the longest substring with all unique characters
    }
};
