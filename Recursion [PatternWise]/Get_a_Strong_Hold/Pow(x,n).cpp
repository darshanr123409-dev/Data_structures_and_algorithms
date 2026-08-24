#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {

        long long num = n;

        // Handle negative exponent
        if (num < 0) {
            x = 1 / x;
            num = -num;
        }

        double ans = 1.0;

        // Binary Exponentiation
        while (num > 0) {

            // If num is odd
            if (num % 2 == 1) {
                ans *= x;
            }

            // Square the base
            x *= x;

            // Divide exponent by 2
            num = num / 2;
        }

        return ans;
    }
};

int main() {
    Solution obj;

    double x;
    int n;

    cin >> x >> n;

    cout << obj.myPow(x, n) << endl;

    return 0;
}