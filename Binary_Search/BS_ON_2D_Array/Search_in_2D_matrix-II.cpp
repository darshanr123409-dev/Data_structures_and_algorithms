#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // TC = O(n+m) and SC = O(1)
        int n= matrix.size(); // rows
        int m= matrix[0].size(); // colums
        int row=0;
        int col = m-1;
        while(row<n && col>=0){
            if(matrix[row][col]==target) {
                return true ;
            }
            else if(matrix[row][col]>target) {
                col--;
            }
            else {
                row++;
            }
        } // vertical wised problems
        return false ;
    }
};  
