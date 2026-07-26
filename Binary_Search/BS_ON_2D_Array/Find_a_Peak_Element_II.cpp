#include <bits/stdc++.h>
using namespace std;

// Find the row index of the maximum element
// in the given column
int max_element(vector<vector<int>> &arr, int n, int m, int col) {

    int max_ele = INT_MIN;
    int index = -1;

    for (int i = 0; i < n; i++) {

        if (arr[i][col] > max_ele) {
            max_ele = arr[i][col];
            index = i;
        }
    }

    return index;
}

vector<int> Find_peak_Element_2(vector<vector<int>> &arr) {

    int n = arr.size();       // Number of rows
    int m = arr[0].size();    // Number of columns

    // Binary search on columns
    int low = 0;
    int high = m - 1;

    while (low <= high) {

        // Find middle column
        int mid = (low + high) / 2;

        // Find maximum element's row
        // in the middle column
        int max_index = max_element(arr, n, m, mid);

        // Check left neighbor
        int left = (mid - 1 >= 0)
                   ? arr[max_index][mid - 1]
                   : -1;

        // Check right neighbor
        int right = (mid + 1 < m)
                    ? arr[max_index][mid + 1]
                    : -1;

        // Current element
        int current = arr[max_index][mid];

        // Check if current element is a peak
        if (current > left && current > right) {

            return {max_index, mid};
        }

        // Left neighbor is greater
        // Search in left half
        else if (current < left) {

            high = mid - 1;
        }

        // Right neighbor is greater
        // Search in right half
        else {

            low = mid + 1;
        }
    }

    return {-1, -1};
}