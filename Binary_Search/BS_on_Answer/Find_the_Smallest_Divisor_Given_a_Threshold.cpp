#include <bits/stdc++.h>
using namespace std;

    // Calculate sum of ceil(arr[i] / div)
int Divisor(vector<int>& arr, int div) {

        int sum = 0;

        for (int i = 0; i < arr.size(); i++) {

            sum += ceil((double)arr[i] / div);
        }

        return sum;
}

int smallestDivisor(vector<int>& nums, int threshold) {

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        int ans = 0;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (Divisor(nums, mid) <= threshold) {

                // Possible answer
                ans = mid;

                // Try to find smaller divisor
                high = mid - 1;
            }
            else {

                // Sum is too large
                // Need a bigger divisor
                low = mid + 1;
            }
        }

        return ans;
}
