#include <bits/stdc++.h>
using namespace std;

void Reverse_strings(string s){

    int left =0;
    int right = s.size();
    while(left<right){
        swap(s[left],s[right]);
        left++,right--;
    }

}