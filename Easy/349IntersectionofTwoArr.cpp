// Problem: Intersection of Two Arrays
// Link: https://leetcode.com/problems/intersection-of-two-arrays/
// Difficulty: Easy
// Approach: Two Pointers + Unique Elements — sort both arrays, use two pointers,
//           add element only if it's common AND not already added to result.
// Time: O(n log n + m log m) | Space: O(min(n, m))

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = 0, j = 0;
        vector<int> result;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                // add only if unique
                if (result.empty() || result.back() != nums1[i]) {
                    result.push_back(nums1[i]);
                }
                i++;
                j++;
            } 
            else if (nums1[i] < nums2[j]) {
                i++;
            } 
            else {
                j++;
            }
        }

        return result;
    }
};