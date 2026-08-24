#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int helper(string &s, int i, long long num, int sign) {

        // Base case
        if (i >= s.size() || !isdigit(s[i])) {
            return sign * num;
        }

        // Add current digit
        num = num * 10 + (s[i] - '0');

        // Overflow check
        if (sign * num >= INT_MAX)
            return INT_MAX;

        if (sign * num <= INT_MIN)
            return INT_MIN;

        // Recursive call
        return helper(s, i + 1, num, sign);
    }

    int myAtoi(string s) {

        int i = 0;

        // Skip leading spaces
        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        // Handle sign
        int sign = 1;

        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {

            if (s[i] == '-') {
                sign = -1;
            }

            i++;
        }

        // Start recursion
        return helper(s, i, 0, sign);
    }
};