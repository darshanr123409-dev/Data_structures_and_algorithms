#include<bits/stdc++.h>
using namespace std;

int Roate_array_90(vector<vector<int>> &arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(a[i][j],a[j][i])
        }
    }
    for(int i=0;i<n;i++){
        reverse(arr[i].begin(),arr[i].end());
    }
    return arr;
}