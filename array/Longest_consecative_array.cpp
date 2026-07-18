#include<bits/stdc++.h>
using namespace std;

// bool linear_search(vector<int> arr, int target){
//     int n=arr.size();
//     for(int i=0;i<n;i++){
//         if(arr[i]==target){
//             return true;
//         }
//     }
//     return false;
// }    
// int Longest_consecative_array(vector<int> arr){
//     int n=arr.size();
//     if(n==0){
//         return 0;
//     }
//     int large=INT16_MIN;
//     for(int i=0;i<n;i++){
//         int current = arr[i];
//         int count =1;
//         while(linear_search(arr, current + 1) == true){
//             current++;
//             count++;
//         }
//         large = max(count, large);
//     }

//     return large;
// }

// int Longest_consecative_array(vector<int> arr){
//     int n=arr.size();
//     if(n==0){
//         return 0;
//     }
//     int large_min=INT_MIN;
//     int cnt=0;
//     int large=1;

//     sort(arr.begin(),arr.end());

//     for(int i=0;i<n;i++){
//         if(arr[i]-1==large_min){
//             cnt++;
//             large_min=arr[i];
//         }
//         else if(large_min!=arr[i]){
//             cnt=1;
//             large_min=arr[i];
//         }
//         large=max(large,cnt);
//     }
//     return large;
// }

int Longest_consecative_array(vector<int> arr){
    int n=arr.size();
    if(n==0){
        return 0;
    }
    unordered_set<int> st(arr.begin(),arr.end());
    int cnt=0;
    int large=1;
    for(auto it : st){
        if(st.find(it-1)==st.end()){
            cnt=1;
            int x=it;
        
        while(st.find(x+1)!=st.end()){
            x=x+1;
            cnt++;
        
        }
    }
        large=max(large,cnt);
    }
    return large;
}

int main() {
    vector<int> arr = {100, 4, 200, 1, 3, 2};
    int result = Longest_consecative_array(arr);
    
    cout << "Length of the longest consecutive elements sequence: " << result << endl;
    
    return 0; // time complexity: O(n^2), and space complexity: O(1)
}


