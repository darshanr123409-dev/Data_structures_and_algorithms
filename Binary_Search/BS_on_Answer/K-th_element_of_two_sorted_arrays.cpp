#include<bits/stdc++.h>
using namespace std;
 
double long Kth_Element(vector<int> &nums1,vector<int> &nums2,int n1,int n2,int k) {  
    if (nums1.size() > nums2.size()) {
            return Kth_Element(nums2, nums1,n2,n1,k);
        }

        int low = max(0,k-n2);
        int high = min(k,n1);

        // Number of elements on left side
        int left = k;

        while (low <= high) {

            int mid1 =  (high+low) / 2;
            int mid2 = left - mid1;

            // Left and right values
        int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
        int r1 = (mid1 == n1) ? INT_MAX : nums1[mid1];

        int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
        int r2 = (mid2 == n2) ? INT_MAX : nums2[mid2];
            // Correct partition
            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            }

            // We took too many elements from nums1
            else if (l1 > r2) {
                high = mid1 - 1;
            }

            // We took too few elements from nums1
            else {
                low = mid1 + 1;
            }
        }

        return 0.0;
    }