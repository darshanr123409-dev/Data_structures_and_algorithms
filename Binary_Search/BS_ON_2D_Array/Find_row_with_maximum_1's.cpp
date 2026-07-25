#include <bits/stdc++.h>
using namespace std;

// int find_the_minmum_Number_1s(vector<vector<int>> &arr){
//     int n=arr.size();
//     int m=arr[0].size();
//     int Max=INT_MIN;
//     int index=-1;
//Tc = O(n*2) and Sc = O(1)
//     for(int i=0;i<n;i++){
//         int count_row=0;
//         for(int j=0; j<m ;j++){
//             count_row+=arr[i][j];
//         }
//         if(count_row>Max){
//             Max=count_row;
//             index=i;
//         }
//     }
//     return index;
// }

int lower_bond(vector<int> &arr,int n,int x){
    int ans;
    int low=0;
    int high =n-1;
    while(low<=high){
        int mid = (low + high) /2;

        if(arr[mid] >= x){
            ans=mid;
            high=mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
// Tc = O(n log n) and Sc = O(1)
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {

    int cnt_max = 0;
    int index = -1;
    // row
    for (int i = 0; i < n; i++) {
        // m=number od colums 
        int cnt_ones = m - lower_bond(matrix[i], m, 1); // ans =3
            // 5 -3=3
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }

    return index;
}

	