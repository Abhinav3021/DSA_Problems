/*
Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
Example 2:

Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.
*/


#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<string> result;

    // Helper function for recursive backtracking
    void func(string s, vector<string>& wordDict, int i, string words) {
        int n = s.size();
        
        // Base case: if the end of the string is reached, remove trailing space and add to result
        if (i == n) {
            words.pop_back(); // Remove trailing space
            result.push_back(words);
            return;
        }
        
        // Try different substrings starting from index i
        for (int j = i; j <= n; j++) {
            // If the substring is in wordDict
            if (count(wordDict.begin(), wordDict.end(), s.substr(i, j - i))) {
                string s1 = s.substr(i, j - i); // Extract current substring
                // Recursive call with the current substring added to the sentence
                func(s, wordDict, j, words + s1 + " ");
            }
        }
    }

    // Main function to break the word
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string words; // Empty string to accumulate words
        func(s, wordDict, 0, words); // Start backtracking
        return result;
    }
};
