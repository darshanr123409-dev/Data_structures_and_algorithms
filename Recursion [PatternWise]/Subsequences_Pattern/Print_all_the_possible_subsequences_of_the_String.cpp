#include <bits/stdc++.h>
using namespace std;

// Power Set / All Subsequences
// Approach 1: Recursion

class Solution {
public:

    void helper(string &s, int index, string current,
                vector<string> &result) {

        // Base case
        if (index == s.size()) {
            result.push_back(current);
            return;
        }

        // 1. Exclude current character
        helper(s, index + 1, current, result);

        // 2. Include current character
        current.push_back(s[index]);

        helper(s, index + 1, current, result);

        // Backtrack
        current.pop_back();
    }

    vector<string> getSubsequences(string s) {

        vector<string> result;

        string current = "";

        helper(s, 0, current, result);

        return result;
    }

    // Approach 2
     vector<string> getSubsequences(string s) {
        // Length of input string
        int n = s.size();

        // Total subsequences = 2^n
        int total = 1 << n;

        // Vector to store all subsequences
        vector<string> subsequences;

        // Iterate over all bit masks from 0 to 2^n - 1
        for (int mask = 0; mask < total; mask++) {
            // Temporary subsequence string
            string subseq = "";

            // Check each bit position in mask
            for (int i = 0; i < n; i++) {
                // If i-th bit of mask is set, include s[i]
                if (mask & (1 << i)) {
                    subseq += s[i];
                }
            }

            // Store the formed subsequence
            subsequences.push_back(subseq);
        }

        // Return all generated subsequences
        return subsequences;
    }
};