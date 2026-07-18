#include<bits/stdc++.h>
using namespace std;

int Xor_count_subarray(vector<int>  & arr,int k){

    int n=arr.size();
    map<int,int> mapp;
    int count=0;
    int xr=0;
    mapp[xr]++; // {0:1}

    for(int i=0;i<n;i++){
        xr^=arr[i];
        int x=k^xr;
        if(mapp.find(x)!=mapp.end()){
            count+=mapp[x];
        }
        mapp[xr]++;
    }
    return count;
}
