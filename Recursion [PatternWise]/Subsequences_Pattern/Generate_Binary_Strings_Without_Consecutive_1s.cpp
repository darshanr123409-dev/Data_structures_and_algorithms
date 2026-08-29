#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(int n, string &s, vector<string> &ans) {

        if (s.length() == n) {
            ans.push_back(s);
            return;
        }

        // Add 0
        s.push_back('0');
        solve(n, s, ans);
        s.pop_back();

        // Add 1 only when previous character is 0
        if (s.empty() || s.back() == '0') {
            s.push_back('1');
            solve (n, s, ans);
            s.pop_back();
        }
    }

    vector<string> generateBinaryStrings(int n) {

        vector<string> ans;
        string s;

        solve(n, s, ans);

        return ans;
    }
};