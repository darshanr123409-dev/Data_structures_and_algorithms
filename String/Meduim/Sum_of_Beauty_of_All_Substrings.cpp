#include <bits/stdc++.h>
using namespace std;

int Sum_of_Beaty(string s){
    int n=s.size();
    int ans=0;

    for(int i=0 ;i<n ;i++){
        unordered_map<char,int> fre;
        for(int j =i ;j<n ;j++){
            
            fre[s[j]]++;
            int maxi=INT_MIN;
            int mini=INT_MAX;

            for(auto i : fre){
                maxi = max(maxi,i.second);
                mini = min(mini,i.second);
            }
            ans +=(maxi-mini);
        }

    }
        return ans;
}