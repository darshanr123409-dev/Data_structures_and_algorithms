#include<bits/stdc++.h>
using namespace std;

int First_Occurence(vector<int> &arr,int n,int target){
    int first=-1;
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){ // <-------
            first=mid;
            high=mid-1;
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }
    return first;
}
int Last_Occurence(vector<int> &arr,int n,int target){
    int last=-1;
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        //----->
        if(arr[mid]==target){
            last=mid;
            low=mid+1;
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }
    return last;
}
pair<int,int> Get_Fisrt_and_Last_occ(vector<int> &arr,int n,int x){
        
    int first=First_Occurence(arr,n,x);
    if(first==-1)  {
        return {-1,-1};
    }
    int last=Last_Occurence(arr,n,x);
    return {first,last};
}



int count(vector<int> &arr,int n,int x){
    pair<int,int> ans= Get_Fisrt_and_Last_occ(arr,n,x);
     if(ans.first==-1)  {
        return 0;
    }
    return ans.second-ans.first+1;

}