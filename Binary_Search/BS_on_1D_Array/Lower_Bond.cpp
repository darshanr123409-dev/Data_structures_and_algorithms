#include<bits/stdc++.h>
using namespace std;

int Lower_bond(vector<int> &arr,int target){
    int n=arr.size();
    int ans=n;
    int low=0;   //   Tc= O(n log n)
    int high=n-1;  //  Sc =O(1)
    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]>=target){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}