#include<bits/stdc++.h>
using namespace std;

vector<int> Majority_element_3(vector<int> &arr){

    map<int,int> mapp;
    vector<int> ls;             // TC is O(n) 
                                // SC is O(n)
    int n=arr.size();
    int min=(n/3)+1;

    for(auto i =0; i<n;i++){
        mapp[arr[i]]++;
        if(mapp[arr[i]]==mm){
            ls.push_nack(arr[i]);
        }
        if(ls.size()==2) {
            break;
        }
    }
    sort(ls.begin(),ls.end());
    return ls;
}

vector<int> Majority_element_3(vector<int> &arr){
    int n=arr.size();

    int cnt1=0,cnt2=0;
    int el1=INT_MIN,el2=INT_MIN;

    for(int i=0 ;i<n ;i++){
        if(cnt1==0 && arr[i]!=el2) {
            cnt1=1;
            el1=arr[i];
        }
        else if(cnt2==0 && arr[i]!=el1) {
            cnt2=1;
            el2=arr[i];
        }
        else if(arr[i]==el1) cnt1++;
        else if(arr[i]==el2) cnt2++;
        else cnt1--,cnt2--;
    }
    vector<int> v;
    int c1=0,c2=0;

    for(int i=0;i<n;i++){
        if(arr[i]==el1) c1++;
        if(arr[i]==el2) c2++;
    }
    int mx=(n/3)+1;

    if(c1>=mx)   v.push_back(el1);
    if(c2>=mx)   v.push_back(el2);
    
    return v;  

}    