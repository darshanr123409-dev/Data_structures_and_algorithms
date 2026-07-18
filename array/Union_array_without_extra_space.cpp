#include<bits/stdc++.h>
using namespace std;

void  Union_array_without_extra_space(vector<int> &arr1,vector<int> &arr2){
    int n=arr1.size();
    int m=arr2.size();

    int left=n-1; // <-----  this way 
    int right=0; // ------> this way 
    while(left>=0 && right<m){
        if(arr1[left]>arr2[right]){ // compare the left arr1 > arr2 then swap
            swap(arr1[left],arr2[right]);
            left--; // decrease
            right++; // increase
        }
        else {
            break; // when is arr2 is higher then loop will be a stop
        }
    }
    sort(arr1.begin(),arr1.end()); // SC is 0(1)
    sort(arr2.begin(),arr2.end());  // TC is O(min(n,m) + n log n+ m Log m ) 
}
int main()
{
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {0, 2, 6, 8, 9};

    Union_array_without_extra_space(arr1, arr2);

    cout << "Array 1: ";
    for (int x : arr1)
        cout << x << " ";

    cout << "\nArray 2: ";
    for (int x : arr2)
        cout << x << " ";

    return 0;
}