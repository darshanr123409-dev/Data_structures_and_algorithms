#include <bits/stdc++.h>
using namespace std;

vector<int> Union_of_sorted_array(vector<int> arr1, vector<int> arr2){
    int n = arr1.size();
    int m = arr2.size();
    int i=0;
    int j=0;
    vector<int> Union ;

    while( i<n && j<m ){

        if(arr1[i]<arr2[j]){
            if(Union.empty() or Union.back() != arr1[i]){
                Union.push_back(arr1[i]);
             }
        i++;
        }
        else if(arr2[j]<arr1[i]){
            if(Union.empty() or Union.back() != arr2[j]){
                Union.push_back(arr2[j]);
             }
        j++;
        }
        else {
            if(Union.empty() or Union.back() != arr1[i]){
                Union.push_back(arr1[i]);
             }
             i++,j++;
        }
    }
     while( i<n ){
       if(Union.empty() or Union.back() != arr1[i]){
                Union.push_back(arr1[i]);
             }
        i++;
    }

     while( j<m ){
        if(Union.empty() or Union.back() != arr2[j]){
            Union.push_back(arr2[j]);
        }
        j++;
}
    return Union;
}