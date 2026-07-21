#include <bits/stdc++.h>
using namespace std;

int Minimum_in_Rotated_Sorted_Array_II(vector<int> &arr) {

    int low = 0;
    int high = arr.size() - 1;

    while (low < high) { // [2 2 2 0 1 2 ]

        int mid = (low + high) / 2;
            // when a mid high then low move  the  low is mid+1
        if (arr[mid] > arr[high]) {
            low = mid + 1;
        }
        // when a mid low then high move the is mid
        else if (arr[mid] < arr[high]) {
            high = mid;
        }
        // mid == high
        else {
            high--;
        }
    }
    
    return arr[low];
}
