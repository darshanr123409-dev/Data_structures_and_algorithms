#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //   TC = O(m + n) and SC = O(1)
    //     int n=matrix.size();
    //     int m=matrix[0].size();
    //     int i=0;
    //     int j=m-1;
    //     while(i<n && j>=0){
    //         if(matrix[i][j]==target){
    //             return true;
    //         }
    //         else if(matrix[i][j] > target) {
    //             j--;
    //         }
    //         else{
    //             i++;
    //         }
    //     }
    //     return false;
    // }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//   TC = O(log (m + n)) and SC = O(1)
         int m = matrix.size();
        int n = matrix[0].size();

        int left = 0, right = m * n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int row = mid / n;
            int col = mid % n;

            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return false;
        
    }
};