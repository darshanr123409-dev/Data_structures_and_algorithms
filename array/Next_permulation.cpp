#include<bits/stdc++.h>
using namespace std;

// vector<int> next_permutation(vector<int>& nums) {
//     next_permutation(nums.begin(), nums.end());
//     return nums;
// }
// int main() {
//     vector<int> nums = {3, 1, 2};
//     vector<int> result = next_permutation(nums);
    
//     cout << "Next permutation: ";
//     for (int num : result) {
//         cout << num << " ";
//     }
//     cout << endl;
    
//     return 0; // time complexity: O(n), and space complexity: O(1)
// }
vector<int> next_permutation(vector<int>& nums) {
int n = nums.size();
int index = -1;
for(int i=n-2;i>=0;i--){
    if(nums[i]<nums[i+1]){
        index=i;
        break;
    }
}

if(index==-1){
    reverse(nums.begin(),nums.end());
}
for(int i=n-1;i>index;i--){
    if(nums[i]>nums[index]){
        swap(nums[i],nums[index]);
        break;
    }
}
reverse(nums.begin()+index+1,nums.end());
return nums;
}

int main() {
    vector<int> nums = {2, 1, 5, 4, 3, 0, 0};
    vector<int> result = next_permutation(nums);
    
    cout << "Next permutation: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
return 0;// time complexity: O(n), and space complexity: O(1)
}




