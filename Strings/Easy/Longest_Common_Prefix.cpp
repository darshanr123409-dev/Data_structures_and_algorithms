#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Brute Force        
        // string ans= "";
        // for(int i=0 ;i<strs[0].size() ;i++){
        //     for(int j=1 ;j<strs.size() ;j++){
        //         if(strs[j][i]!=strs[0][i]){
        //             return ans; // Empty 
        //         }
        //     }
        //     ans +=strs[0][i];
        // }
        // return ans; // answer TC = O(nXm) and O(1)


        // Optimal solution 
        string ans ="";
        sort(strs.begin(),strs.end());
        int i=0;

        while( i<strs[0].size() and strs[0][i]==strs[strs.size()-1][i]){
            ans +=strs[0][i];
            i++;
        }
        return ans; // TC = O(n  log n + M) and SC = O(1)
    }
};