/*Given a word pat and a text txt. Return the count of the occurrences of anagrams of the word in the text.

Example 1:

Input:
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.
*/

#include<bits/stdc++.h>
using namespace std ;

#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int search(string pat, string txt) {
        int result = 0;
        unordered_map<char, int> m;
        unordered_set<char> petSet(pat.begin(), pat.end());
        
        // Initialize the map with the frequency of each character in 'pat'
        for (char i : pat) {
            m[i]++;
        }
        
        int c = petSet.size(); // Count of unique characters with non-zero frequency in the map

        // Set up the initial window
        for (int i = 0; i < pat.size(); i++) {
            if (petSet.count(txt[i]) > 0) {
                m[txt[i]]--;
                if (m[txt[i]] == 0) {
                    c--;
                }
            }
        }
        
        // Check if the initial window is a match
        if (c == 0) {
            result++;
        }
        
        // Slide the window
        for (int i = pat.size(); i < txt.size(); i++) {
            // Remove the character going out of the window
            char oldChar = txt[i - pat.size()];
            if (petSet.count(oldChar) > 0) {
                if (m[oldChar] == 0) {
                    c++;
                }
                m[oldChar]++;
            }

            // Add the character coming into the window
            char newChar = txt[i];
            if (petSet.count(newChar) > 0) {
                m[newChar]--;
                if (m[newChar] == 0) {
                    c--;
                }
            }

            // Check if all required characters have matched
            if (c == 0) {
                result++;
            }
        }
        
        return result;
    }
};
