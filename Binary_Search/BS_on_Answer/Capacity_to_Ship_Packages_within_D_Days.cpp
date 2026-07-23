#include <bits/stdc++.h>
using namespace std;
    // if ship capacity is 'capacity'
    int countDays(vector<int>& weights, int capacity) {

        int days = 1;
        int currentLoad = 0;

        for (int weight : weights) {

            // If adding this package exceeds capacity
            if (currentLoad + weight > capacity) {

                // Start shipping on next day
                days++;

                // Put current package on the new day
                currentLoad = weight;
            }
            else {
                currentLoad += weight;
            }
        }

        return days;
    }


    int shipWithinDays(vector<int>& weights, int days) {

        // Minimum capacity:
        // At least the heaviest package
        int low = *max_element(weights.begin(), weights.end());

        // Maximum capacity:
        // Ship all packages in one day
        int high = accumulate(weights.begin(), weights.end(), 0);

        int ans = high;

        while (low <= high) { //
//weights = {1,2,3,4,5,6,7,8,9,10}
//low  = 10
//high = 55
            int mid = (high + low) / 2;

            // Can we ship all packages within 'days'?
            if (countDays(weights, mid) <= days) {

                // Possible answer
                ans = mid;

                // Try smaller capacity
                high = mid - 1;
            }
            else {

                // Need bigger capacity
                low = mid + 1;
            }
        }

        return ans;
    }