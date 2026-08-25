#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Modulo value given in the problem
    long long MOD = 1000000007;

    // Fast Power: calculates (a^b) % MOD
    // Time Complexity: O(log b)
    long long power(long long a, long long b) {
        long long ans = 1;

        while (b > 0) {

            // If b is odd
            if (b & 1) {
                ans = (ans * a) % MOD;
            }

            // Square a
            a = (a * a) % MOD;

            // Divide exponent by 2
            b /= 2;
        }

        return ans;
    }

    int countGoodNumbers(long long n) {

        // Even positions: 0, 2, 4, ...
        // Number of even positions = (n + 1) / 2
        long long evenPositions = (n + 1) / 2;

        // Odd positions: 1, 3, 5, ...
        // Number of odd positions = n / 2
        long long oddPositions = n / 2;

        // Every even position has 5 choices:
        // 0, 2, 4, 6, 8
        long long evenWays = power(5, evenPositions);

        // Every odd position has 4 choices:
        // 2, 3, 5, 7
        long long oddWays = power(4, oddPositions);

        // Total ways
        return (evenWays * oddWays) % MOD;
    }
};