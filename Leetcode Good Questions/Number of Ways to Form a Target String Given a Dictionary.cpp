
/*
Question Link:- https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/?envType=daily-question&envId=2024-12-29
*/

class Solution {
public:
    const int MOD = 1e9 + 7;

    int func(vector<vector<int>>& freq, string& target, int i, int pos, vector<vector<int>>& memo) {
        // Base case: If we have formed the target
        if (i == target.size()) return 1;

        // If the position exceeds the frequency table
        if (pos >= freq[0].size()) return 0;

        // Check if already computed
        if (memo[i][pos] != -1) return memo[i][pos];

        // Recursive case
        long long ways = 0;

        // Use the current character in target
        if (freq[target[i] - 'a'][pos] > 0) {
            ways += (long long)freq[target[i] - 'a'][pos] * func(freq, target, i + 1, pos + 1, memo);
            ways %= MOD;
        }

        // Skip the current position
        ways += func(freq, target, i, pos + 1, memo);
        ways %= MOD;

        // Store in memo and return
        return memo[i][pos] = ways;
    }

    int numWays(vector<string>& words, string target) {
        int n = words[0].size();
        vector<vector<int>> freq(26, vector<int>(n, 0));

        // Build frequency table for characters at each position
        for (const string& word : words) {
            for (int i = 0; i < n; ++i) {
                freq[word[i] - 'a'][i]++;
            }
        }

        // Memoization table: target size x word length
        vector<vector<int>> memo(target.size(), vector<int>(n, -1));

        return func(freq, target, 0, 0, memo);
    }
};
