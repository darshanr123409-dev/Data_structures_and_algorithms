#include<bits/stdc++.h>
using namespace std;

int Count_subarray(vector<int> &arr,int k){
    int n=arr.size();
    int count=0;
    int pre_sum=0;
    map<int,int> mp;
    mp[0]=1;

    for(int i=0;i<n;i++)
    {
        pre_sum=pre_sum+arr[i];
        int rem=pre_sum-k;
        if(mp.find(rem)!=mp.end())
        {
            count+=mp[rem];
        }
        mp[pre_sum]+=1;

    }
    return count;
}
int main()
{
    int k;
    cout<<"Enter the value of k: \n";
    cin>>k;
    vector<int> arr = {1,2,3,-3,3,1,1,1,4,2,-3};
    int count=Count_subarray(arr,k);
    cout<<"The number of subarrays with sum "<<k<<" is "<<count;
    return 0;

}