#include <bits/stdc++.h>
using namespace std;

// Calculate total hours needed to eat all bananas
long long calculateTotalHours(vector<int>& piles, int speed) {

    long long totalH = 0;

    for (int bananas : piles) {

        // Ceiling division:
        // ceil(bananas / speed)
        totalH += ((long long)bananas + speed - 1) / speed;
    }

    return totalH;
}


int minEatingSpeed(vector<int>& piles, int h) {

    // Maximum pile = maximum possible eating speed
    int maxPile = *max_element(piles.begin(), piles.end());

    // Binary search range
    int low = 1;
    int high = maxPile;

    int ans = maxPile;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        // Hours needed at speed 'mid'
        long long totalH = calculateTotalHours(piles, mid);

        // If Koko can finish within h hours
        if (totalH <= h) {

            // mid is a possible answer
            ans = mid;

            // Try to find a smaller speed
            high = mid - 1;
        }
        else {

            // Speed is too slow
            // Increase the speed
            low = mid + 1;
        }
    }

    return ans;
}