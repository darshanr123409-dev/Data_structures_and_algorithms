#include <bits/stdc++.h>
using namespace std;

int Minimum_in_Rotated_Sorted_Array_II(vector<int> &arr) {

    int low = 0;
    int high = arr.size() - 1;

    while (low < high) {

        int mid = (low + high) / 2;

        if (arr[mid] > arr[high]) {
            low = mid + 1;
        }
        else if (arr[mid] < arr[high]) {
            high = mid;
        }
        else {
            high--;
        }
    }

    return arr[low];
}
