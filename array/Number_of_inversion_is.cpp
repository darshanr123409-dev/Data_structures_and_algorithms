#include<bits/stdc++.h>
using namespace std;

//brute force
// int Count_inversion_of_array(vector<int> &arr){
//     int n=arr.size();  // Tc is O(n^2) Sc is O(1)
//     int cnt=0;
//     for(int i=0;i<n ;i++){
//         for(int j=i+1 ;j<n;j++){
//             if(arr[i]>arr[j]){
//                 cnt++;
//             }
//         }
//     }
//     return cnt ;
// }

// optimal Solution 
// Tc = O(n log n)
// Sc = O(n)
    // Function to merge two halves of the array
    int  merge(vector<int>& arr, int low, int mid, int high) {
        // Create temp arrays
        vector<int> temp;
        int left = low, right = mid + 1;
        int cnt=0;
        // Merge two sorted halves
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]){
                temp.push_back(arr[left++]);
            }
            else{
                temp.push_back(arr[right++]);
                cnt+=(mid-left+1); // number is right is high then number of left side arr legth add 
            } // imp //\
                      |

        }

        // Copy remaining elements from left half
        while (left <= mid)
            temp.push_back(arr[left++]);

        // Copy remaining elements from right half
        while (right <= high)
            temp.push_back(arr[right++]);

        // Copy sorted elements back to original array
        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
        return cnt;
    }

    // Recursive merge sort function
    int mergeSort(vector<int>& arr, int low, int high) {
        int cnt=0;
        if (low >= high)
            return cnt ; // out of bound cnt is 0

        // Find the middle index
        int mid = (low + high) / 2;

        // Recursively sort left half
        cnt+=mergeSort(arr, low, mid);

        // Recursively sort right half
        cnt+=mergeSort(arr, mid + 1, high);

        // Merge the two sorted halves
        cnt+=merge(arr, low, mid, high);

        return cnt;
}
int Number_of_inversion_is(vector<int> &arr,int n){
    return mergeSort(arr,0,n-1);
}
int main()
{
    vector<int> arr = {5, 3, 2, 4, 1};

    cout << "Number of inversions = "
         << Number_of_inversion_is(arr, arr.size());

    return 0;
}
