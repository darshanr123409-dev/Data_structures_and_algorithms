#include <bits/stdc++.h>
using namespace std;

// TC = O(n) and SC = O(n)
// vector<int> Move_all_zero(vector<int> arr) {
//     int n = arr.size();
//     vector<int> temp;//initialise of n size 0
//     for(auto i : arr){
//         if( i !=0 ){
//             temp.push_back(i);
//         } 
//     }
//    while (temp.size() < n) {
//         temp.push_back(0);
//     }
//     return temp;
// }

vector<int> Move_all_zero(vector<int> arr) {
// TC = o(n) and SC = o(1)
    int n = arr.size();
    int j=-1;
    for( int i =0 ; i<n ;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    if(j == -1) return arr;
    for(int i = j+1 ; i<n ; i++ ){
        if(arr[i] !=0 ){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    return arr;
}
