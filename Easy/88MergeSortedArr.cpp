// Problem: Merge Sorted Array
// Link: https://leetcode.com/problems/merge-sorted-array/
// Difficulty: Easy
// Approach: Two Pointers + Extra Array — use two pointers to traverse both arrays,
//           compare elements and store them in a temporary array (unionArr),
//           then copy the result back into nums1.
// Time: O(m + n) | Space: O(m + n)


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = 0, j = 0;
        vector<int> unionArr;

        // merge both arrays
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                unionArr.push_back(nums1[i]);
                i++;
            } else {
                unionArr.push_back(nums2[j]);
                j++;
            }
        }

        // remaining elements of nums1
        while (i < m) {
            unionArr.push_back(nums1[i]);
            i++;
        }

        // remaining elements of nums2
        while (j < n) {
            unionArr.push_back(nums2[j]);
            j++;
        }

        // copy back into nums1
        for (int k = 0; k < m + n; k++) {
            nums1[k] = unionArr[k];
        }
    }
};