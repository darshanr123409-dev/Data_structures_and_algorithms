#include <bits/stdc++.h>
using namespace std;

int largest_Element(vector<int> arr) {
    int max=arr[0];
    int n=arr.size();
    for( int i=1 ; i<n ;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
    // sort(arr.begin(),arr.end());
    // return arr[n-1];
}