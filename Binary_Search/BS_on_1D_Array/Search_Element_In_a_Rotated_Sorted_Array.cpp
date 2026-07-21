#include<bits/stdc++.h>
using namespace std;

int Search_Elemet_are_rotate_sorted_array(vector<int> &arr,int n,int target){
    //Tc = O(log n)
    // SC = O(1)
    int low=0;
    int high=n-1;

    while(low<=high){

        int mid = (low+high)/2;

        if(arr[mid]==target){
            return mid;
        }
        // when low<= mid 
        if(arr[low]<=arr[mid]){
        // if target >=low & target<=mid high = mid-1 // <--- right 
            if(target>=arr[low] && target<=arr[mid]){
                high = mid-1;
            }
        //else target is high  // go to left ----->
            else {
                low = mid+1;
            }
        }
        else {
            // inverse 
            if(target>=arr[mid] && target<=arr[high]){
                low = mid+1;
            }
            // same inverse
            else {
                high = mid-1;
            }
        }
    }
    return -1;
}