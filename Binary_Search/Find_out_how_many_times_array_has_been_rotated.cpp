//Find out how many times array has been rotated

#include <bits/stdc++.h>
using namespace std;


int  find_how_many_times_in_Rotated_Sorted_Array(vector<int> &arr, int n) {
        int low = 0, high = n - 1;
        int ans = INT_MAX;
        int index=-1;

        while (low <= high) {

           int mid = (low + high) / 2;

            if (arr[low] <= arr[high]) { // ex is{0,1,2}
                if(arr[low]<ans){
                    index=low;
                    ans=arr[low];
                }
                break;      // to find min Left and break;
            }

            if (arr[low] <= arr[mid]) {
                if(arr[low]<ans){
                    index=low;
                    ans=arr[low];
                }
                low = mid + 1;      // to find min Left
            }
            else {
                    
                if(arr[mid]<ans){
                    index=mid;
                    ans=arr[mid];
                // To find the right side 
                      }
            high = mid - 1;
                }
    }
    return index;
}
