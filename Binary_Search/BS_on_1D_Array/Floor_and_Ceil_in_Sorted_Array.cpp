#include <bits/stdc++.h>
using namespace std;

    // Function to find the floor of x
    int  findFloor(vector<int> &arr, int n, int x) {
        int low = 0, high = n - 1;
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] <= x) {
                ans = arr[mid];     // Potential floor
                low = mid + 1;      // Search right side
            } else {
                high = mid - 1;     // Search left side
            }
        }
        return ans;
    }

    // Function to find the ceiling of x
    int findCeil(vector<int> &arr, int n, int x) {
        int low = 0, high = n - 1;
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] >= x) {
                ans = arr[mid];     // Potential ceil
                high = mid - 1;     // Search left side
            } else {
                low = mid + 1;      // Search right side
            }
        }
        return ans;
    }
    pair<int,int> Get_Floor_and_ceil(vector<int> &arr,int n,int x){
        int f=findFloor(arr,n,x);
        int c=findCeil(arr,n,x);
        return {f,c};
    }

int main() {
    vector<int> arr = {2, 4, 6, 8, 10, 12};
    int x = 7;

    pair<int, int> ans = Get_Floor_and_ceil(arr, arr.size(), x);

    cout << "Floor = " << ans.first << endl;
    cout << "Ceil = " << ans.second << endl;

    return 0;
}