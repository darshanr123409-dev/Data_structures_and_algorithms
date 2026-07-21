#include <bits/stdc++.h>
using namespace std;


int  Minimum_in_Rotated_Sorted_Array(vector<int> &arr, int n) {
        int low = 0, high = n - 1;
        int ans = INT_MAX;

        while (low <= high) {
           int mid = (low + high) / 2;
            if (arr[low] <= arr[high]) { // ex is{0,1,2}
                ans =min(ans,arr[low]);   
                break;      // to find min Left and break;
            } 
            if (arr[low] <= arr[mid]) {
                ans =min(ans,arr[low]);   
                low = mid + 1;      // to find min Left
            } else {
                high = mid - 1;    
                ans =min(ans,arr[mid]);  // To find the right side 
            }
        }
        return ans;
}
