#include <bits/stdc++.h>
using namespace std;

int find_how_many_times_rotated_array_II(vector<int>& arr) {

    int n = arr.size();

    int low = 0;
    int high = n - 1;

    int ans = INT_MAX;
    int index = -1;

    while (low <= high) {

        // If current range is sorted
        if (arr[low] < arr[high]) { //{0,1,2}

            if (arr[low] < ans) {
                ans = arr[low];
                index = low;
            }

            break;
        }

        int mid = low + (high - low) / 2;

        // Duplicate case skip the duplicates
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low++;
            high--;
        }

        // Left half is sorted
        else if (arr[low] <= arr[mid]) {

            if (arr[low] < ans) {
                ans = arr[low];
                index = low;
            }

            low = mid + 1;
        }

        // Right half is sorted
        else {

            if (arr[mid] < ans) {
                ans = arr[mid];
                index = mid;
            }

            high = mid - 1;
        }
    }

    return index;
}