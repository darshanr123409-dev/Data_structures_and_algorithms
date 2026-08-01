#include <bits/stdc++.h>
using namespace std;

vector<int> left_rotate_array(vector<int> arr) {
    int n =arr.size();
    int tmp = arr[0];

    for(int i =1 ; i<n ;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=tmp;
    
    return arr;

}
 