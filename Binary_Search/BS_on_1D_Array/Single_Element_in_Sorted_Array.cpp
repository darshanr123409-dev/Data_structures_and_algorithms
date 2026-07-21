#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) return nums[0]; // is size is 1 return anser is 1

        if (nums[0] != nums[1]) return nums[0]; // bcz arr[0] is anser , here not is not consider

        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];// bcz arr[n-1] is anser , here not is not consider

        int low = 1; // is low is 1 to start
        int high = n - 2; // is high start is n-2

        while (low <= high) {

            int mid = (low + high) / 2;
                // befor and after not equal mid is answer
            if (nums[mid] != nums[mid - 1] &&
                nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }
            // left { even,odd }
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
                (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {

                low = mid + 1;
            }
            else { //right { odd,even }
                high = mid - 1;
            }
        }

        return -1;
}