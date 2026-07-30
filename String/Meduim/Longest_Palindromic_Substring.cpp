#include <bits/stdc++.h>
using namespace std;
//           "01234"
//Input: s = "babad"
//Output: "bab"
int expand(string s,int left ,int right){
    while(left>=0 && right<s.size() && s[left] == s[right]){
        left--;
        right++;
    }
    return right-left-1;
}

string longestPalindrome(string s) {
    int n=s.size();
    int max_len=1;
    int start=0;
    for(int i=0 ;i<n ;i++){
        int odd = expand(s,i,i);
        int even = expand(s,i,i+1);

        int length = max(odd,even);

        if(length>max_len){
            max_len=length;
            
            start = i-(max_len-1)/2;
        }
    }
    return s.substr(start,max_len);

}