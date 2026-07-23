#include <bits/stdc++.h>
using namespace std;

    int findKthPositive(vector<int>& arr, int k) {

        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {

            int mid =  (high + low) / 2;

            // Number of positive integers missing
            // before arr[mid]
            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                // Need to search on the right
                low = mid + 1;
            }
            else {
                // Possible answer is on the left
                high = mid - 1;
            }
        }

        // 'high' missing numbers are before the answer
        return low + k;
    }
