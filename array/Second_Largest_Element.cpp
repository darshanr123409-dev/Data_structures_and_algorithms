#include <bits/stdc++.h>
using namespace std;

int Second_largest_Element(vector<int> arr) {
    int Large=arr[0];
    int n=arr.size();
    int second_large=0;
    for( int i=1 ; i<n ;i++){
        if(arr[i]>Large){
            second_large=Large;
            Large=arr[i];
        }
        else if(arr[i]> second_large && arr[i] != Large){
            second_large=arr[i];
        }
        }

    return second_large;
    // sort(arr.begin(),arr.end());
    // return arr[n-2];
}