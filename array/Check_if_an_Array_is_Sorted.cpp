#include<bits/stdc++.h>
using namespace std;

int check_sorted(vector<int> arr){
    int n = arr.size();
    for(int i =0 ; i<n ;i++ ){
        if(arr[i]<arr[i+1]){

        }
        else {
            return false;
        }
    }
    return true;
}