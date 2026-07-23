#include <bits/stdc++.h>
using namespace std;

    // TC  = O(n × log(maxi - mini + 1))
    // SC  = O(1)
// Check if we can make m bouquets by 'day'
bool possible(vector<int>& arr, int day, int m, int k) {

    int bouquets = 0;       // Day means array numbers given 
    int flowers = 0;

    for (int bloomDay : arr) {
            //when a  bloomday under the day flowers is increase
        // Flower has bloomed
        if (bloomDay <= day) {
            flowers++;

            // We have enough flowers for one bouquet
            if (flowers == k) { // ex is k = 3 
                bouquets++; // bouquets is incraese in ex is under oe equal to M
                flowers = 0; // then is flower is 0 
            }
        }
        else {
            // Consecutive flowers are broken
            flowers = 0;  
        }
    }

    return bouquets >= m; // under the m
}

int roseGarden(vector<int>& arr, int k, int m) {

    // Total flowers required
    long long total = 1LL * k * m;

    // Not enough flowers available
    if (total > arr.size()) {
        return -1;
    }

    // Minimum and maximum bloom days
    int mini = *min_element(arr.begin(), arr.end());
    int maxi = *max_element(arr.begin(), arr.end());

    // Binary search on answer
    int low = mini;
    int high = maxi;
    int result = -1;
    
    while (low <= high) {

        int mid = (high + low) / 2;

        if (possible(arr, mid, m, k)) {

            result = mid; // its a true is then mid assigned by result
            high = mid - 1; // move the high is mid-1
        }
        else {
            low = mid + 1; // false then move the low
        }
    }

    return result;
}