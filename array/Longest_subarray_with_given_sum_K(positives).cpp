#include <bits/stdc++.h>
using namespace std;
//Better Solutionn : pre_sum and Tc = O(n) and Sc =O(n) 
// compute length of the longest subarray with sum k
int maxLen(vector<int> arr, int k) {
  // map prefix sum -> first index seen
  unordered_map<int, int> mpp;
  // best length so far
  int maxi = 0;
  // running prefix sum
  int sum = 0;
    int n = arr.size();
  // iterate over the array
  for (int i = 0; i < n; i++) {
    // update running sum
    sum += arr[i];
    if(sum == k) {
        maxi = max(maxi,i+1);
    }
    long long rem = sum-k;
    if(mpp.find(rem)!=mpp.end()){
        int len = i - mpp[rem];
        maxi = max(maxi,len);
    }
    if(mpp.find(sum) == mpp.end()){
        mpp[sum]=i;
    }
  }
  // return best length
  return maxi;
}
//Optimal Solution :(Only Positive) 2 pointer
// Tc = O(n) and Sc = O(1)

int maxLen(vector<int> arr, int k) {
    int n= arr.size();
    int maxi = 0;
    int left =0;
    int right = 0;
    int s= arr[0];

    while(right < n){
        while(left <= right && s > k){
            s -= arr[left];
            left++;
        }
        if(s == k){
            maxi =max(maxi ,right - left +1);
        }
        right++;
        if( right<n ){
            s +=arr[right];
        }
    }
  // return best length
  return maxi;
}