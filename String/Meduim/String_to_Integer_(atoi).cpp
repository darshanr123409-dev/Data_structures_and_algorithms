#include <bits/stdc++.h>
using namespace std;

int MyAtoI(string s){
    int n=s.size();

    int i=0;
    // if i is become a space it will  be move on (i++)
    while(i<n && s[i]==' '){
        i++;
    }
    // if i is become a positive and negative 
    // it will  be move on (i++) and is assigned by sign
    int sign =1;
    while(i<n && (s[i]=='+' or s[i]=='-')){
        if(s[i]=='-'){
            sign=-1;
        }
        i++;
    }
    //  is digit
    long long answer=0;
    while(i<n && isdigit(s[i])){
        answer = answer*10+(s[i]-'0'); // 7823 is digit wise
        //Over flow
        if(answer*sign>=INT_MAX){
            return INT_MAX;
        }
        if(answer*sign<=INT_MIN){
            return INT_MIN;
        }
        i++;
    }
    return answer *sign;   

}