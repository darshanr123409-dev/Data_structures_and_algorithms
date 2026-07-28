#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     bool rotateString(string s, string goal) {
// TC = O(n^2) and SC(N)
// 			//your code goes here
//             if(s.size()!=goal.size()){
//                 return false;
//             }
//             int n=s.size();
//             string left ="";
//             for(int i =0; i<n ;i++){
//                 string right = s.substr(i); // [<-left]i[right->]

//             if(right + left == goal){
//                 return true;
//             }
//                 left +=s[i];
//             }
//             return false;
// 		}
// }; 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
// Strings must be of the same length to be rotations of each other
    bool rotateString(string& s, string& goal) {
        if (s.length() != goal.length()) {
            return false;  
        }
        string doubledS = s + s;  // Concatenate s with itself
        return doubledS.find(goal) != string::npos;  // Check if goal is a substring of s + s
    }
};