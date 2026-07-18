#include <bits/stdc++.h>
using namespace std;
// brute force 
// vector<int> Finding_missing_number_and_repeat_num(vector<int> &arr){
//     int repeating=-1;
//     int missing=-1;         //Tc = O(n^2)
//     int n=arr.size();       //Sc = O(1)
//     for(int i=1;i<=n;i++){
//         int cnt=0;
//         for(int j=0 ;j<n ;j++){
//             if(arr[j]==i){
//                 cnt++;
//             }
//         }
//             if(cnt==2){
//                 repeating=i;
//             }
//             else if(cnt==0){
//                 missing=i;
//             }
//             if(repeating!=-1 && missing!=-1){
//                 break;
//             }
//         }
    
//     return {repeating,missing};
// }

// // better solution 
// // Tc = O(2n)
// // Sc = O(n)
// #include <bits/stdc++.h>
// using namespace std;

// vector<int> Finding_missing_number_and_repeat_num(vector<int> &arr){
//     int n=arr.size();
//     int repeating=-1;
//     int missing=-1;
//     vector<int> hashmap (n+1,0);

//     for(auto it : arr){
//         hashmap[it]++;
//     }
//     for(int i=1;i<=n;i++){
//         if(hashmap[i]==2)  repeating=i;
//         else if(hashmap[i]==0)  missing=i;

//         if(repeating!=-1 && missing!=-1){
//             break;
//         }
//     }

//     return {repeating,missing};
// }

vector<int> Finding_missing_number_and_repeat_num(vector<int> &arr){
    int n=arr.size();
    //s-sn
    //s2-s2n
    long long sn = 1LL*n*(n+1)/2; 
    long long s2n = 1LL*n*(n+1)*(2*n+1) /6;
    long long s=0,s2=0;
    for(int i=0 ;i<n ;i++){
        s+=arr[i];
        s2+=1LL*arr[i]*arr[i];
    }
    long long value1 = s-sn; // (x-y)
    long long value2 = s2-s2n;
    value2 = value2 / value1 ; // (x+y)
    long long x = (value1 + value2) /2;
    long long y = x-value1;
     
    return {(int)x,(int)y};

}