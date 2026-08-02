#include<bits/stdc++.h>
using namespace std;

int Linear_Search(vector<int> arr,int x){
    
    for(int i=0 ; i<arr.size() ;i++){
        if(arr[i]==x){
            return i;
        }
    }
    return -1;
}