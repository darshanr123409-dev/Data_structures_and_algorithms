#include<bits/stdc++.h>
using namespace std;

// int Binary_search(vector<int> &arr,int n,int target){
//     int low=0;
//     int high=n-1;
//     while(low<=high){
//         int mid=(low+high)/2; 
//         if(arr[mid]==target){
//             return mid;
//         }
//         else if(arr[mid]>target){
//             high=mid-1;
//         }
//         else {
//             low=mid+1;
//         }
//     }
//     return -1;
// }

// Recursive Binary Search 
// Tc = O(n log n)
// Sc = O(1)
int BinarySearch(vector<int> &arr, int low, int high, int target) {

    // Base case
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
        return mid;

    else if (arr[mid] > target)
        return BinarySearch(arr, low, mid - 1, target);

    else
        return BinarySearch(arr, mid + 1, high, target);
}

int main() {

    vector<int> arr = {2, 4, 6, 8, 10, 12, 14};
    int target = 10;

    int ans = BinarySearch(arr, 0, arr.size() - 1, target);

    if (ans != -1)
        cout << "Element found at index " << ans;
    else
        cout << "Element not found";
} 