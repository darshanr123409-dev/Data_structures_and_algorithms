#include<bits/stdc++.h>
using namespace std;
int Maximum_consecutive_1s(vector<int> &arr){
    int n=arr.size();
    int cnt=0;
    int maxi=INT_MIN;

    for(int i=0 ;i<n ;i++){
        if(arr[i]==1){
            cnt++;
        }
        else {
            cnt=0;
        }
        maxi = max(maxi,cnt);
    }
    return maxi;
}
