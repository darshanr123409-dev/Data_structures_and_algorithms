#include <bits/stdc++.h>
using namespace std;
// 4 solution
//Brute force Tc = O(n^2) and Sc = O(1)
int Finding_missing_number(vector<int> &arr){
    int n=arr.size();
    bool found ;
    for(int i =1 ; i<=n+1; i++){
        found = false;
        for( int j=0 ; j<n ; j++){
            if(arr[j]==i){
                found =true;
                break;
            }
        }
        if(!found){
            return i;
    }
}
    return -1;
}
// Better Solution Tc = O(n) and O(n)
int Finding_missing_number(vector<int> arr){
    int n=arr.size()+1;
    vector<int> Hash(n+1,0);

    for(int i =0 ; i<arr.size();i++){
        Hash[arr[i]]++;
    }
    for(int i=1; i<=n ;i++){
        if(Hash[i] == 0 ){
            return i;
        }
    }
    return -1;
}
//Optimal Solution 1 : Tc = O(n) and Sc =O(1)
int Finding_missing_number(vector<int> arr){
    int n=arr.size()+1;
    int sum=0;

    for(int i=0 ; i<n-1; i++){
        sum += arr[i];
    }
    long long Total_sum = n*1LL*(n+1)/2;

    return Total_sum - sum;
}
//Optimal Solution 2 : Tc = O(n) and Sc =O(1)
int Finding_missing_number(vector<int> arr){
    int n=arr.size()+1;
    int xor2=0;
    int xor1=0;

    for(int i=0 ; i<n-1; i++){
        xor2 ^= arr[i];
    }
    
    for(int i =1 ;i <= n ;i++){
        xor1 ^=i;
    }

    return xor1 ^ xor2;
}
