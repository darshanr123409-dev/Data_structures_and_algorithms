#include<bits/stdc++.h>
using namespace std;
// Brute Force TC = O(n^2) and Sc = O(1)
int Find_the_sigle_Number(vector<int> &arr){
    int n=arr.size();
    
    for(int i =0 ; i<n ;i++ ){
        int cnt=0;
        for(int j =0 ; j<n ; j++ ){
            if(arr[j] == arr[i]){
                cnt++;
            }
       }
       if(cnt == 1){
        return arr[i];
       }
    }
    return -1;
}
// Better solution : Hash map TC = O(n) and SC = O(max_element)
int Find_the_sigle_Number(vector<int> &arr){
    int n=arr.size();
    int maxi =arr[0];
    for(int i =1 ; i<n ;i++){
        maxi = max(maxi,arr[i]);
    }
    vector<int> hash(maxi+1,0);
    for(int i=0 ;i<n ;i++){
        hash[arr[i]]++;
    }    
    for(int i=0 ;i<n ;i++){
        if(hash[arr[i]]==1){
            return arr[i];
        }
    }
      
    return -1;
}
// Optimal solution : TC = O(n) and SC = O(1)
int Find_the_sigle_Number(vector<int> &arr){
    int n=arr.size();
    int xxor=0;
    for(int i=0 ;i<n ;i++){
        xxor ^=arr[i];
    }
    return xxor;
}