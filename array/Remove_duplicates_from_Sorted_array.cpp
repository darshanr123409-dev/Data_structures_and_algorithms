#include<bits/stdc++.h>
using namespace std;

int Remove_Duplicate(vector<int> arr){
    int n= arr.size();
    // Tc =O(n log n) and Sc = O(n log n)
    // set<int> st(arr.begin(), arr.end());
    // vector<int> vector(st.begin(),st.end());
    // return vector;

    // Tc = O(n) and Sc = O(1)
      if (n == 0)
        return 0;

    int i =0;
    for(int j=1 ; j<n ;j++){
        if(arr[j] != arr[i] ){
            i++;
            arr[i]=arr[j];
        }
    }
    return (i+1);

}