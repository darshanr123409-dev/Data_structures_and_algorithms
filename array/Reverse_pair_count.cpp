#include<bits/stdc++.h>
using namespace std;

//brute force 
// Tc = O(n^2) 
// Sc is O(1)
// int Reverse_pair_of_array(vector<int> &arr){  // i<j && a[i]>2*a[j] ;
//     int n=arr.size();  // Tc is O(n^2) Sc is O(1)
//     int cnt=0;
//     for(int i=0;i<n ;i++){
//         for(int j=i+1 ;j<n;j++){
//             if((long long)arr[i]>2LL*arr[j]){  // bcz of Overflow
//                 cnt++;
//             }
//         }
//     }
//     return cnt ;
// }
 
//optimal solution 
// Tc = O(n log n)
// Sc = O(n)
 void merge(vector<int>& arr, int low, int mid, int high) {
        // Create temp arrays
        vector<int> temp;
        int left = low, right = mid + 1;

        // Merge two sorted halves
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else
                temp.push_back(arr[right++]);
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
    }

    int count_pairs(vector<int> &arr,int low,int mid,int high){
        int right= mid+1;
        int cnt=0;
        for(int i=low;i<=mid;i++){ //low to mid
            while(right<=high && (long long)arr[i]>2LL*arr[right]){  // mid+1 to high
                right++; // a[i]>2LL*a[right] then right ++;
            }
            cnt+=(right-mid+1); // every mid+1 to high less then then plus the count 
        }
        return cnt; // return

    }

    // Recursive merge sort function
    int mergeSort(vector<int>& arr, int low, int high) {
        int cnt=0;
        if (low >= high)
            return 0;

        // Find the middle index
        int mid = (low + high) / 2;

        // Recursively sort left half
        cnt+=mergeSort(arr, low, mid); // add cnt ++
        // Recursively sort right half 
        cnt+=mergeSort(arr, mid + 1, high); //add cnt ++
        cnt+=count_pairs(arr,low,mid,high); //add cnt ++
        // Merge the two sorted halves
        merge(arr, low, mid, high);

        return cnt;
    }

    int Reverse_pair_count(vector<int> &arr,int n){
    return mergeSort(arr,0,n-1);
    }
int main()
{
    vector<int> arr = {1, 3, 2, 3, 1};

    cout << "Reverse Pairs = " << Reverse_pair_count(arr, arr.size());

    return 0;
}