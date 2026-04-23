// Problem: Next Permutation
// Link: https://leetcode.com/problems/next-permutation/
// Difficulty: Medium
// Approach:
// 1. Find the first decreasing element from right (pivot)
// 2. Find just greater element than pivot from right
// 3. Swap them
// 4. Reverse the suffix
// Time: O(n) | Space: O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // 🔹 Step 1: Find pivot
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // 🔹 Step 2: Find next greater element
        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }

        // 🔹 Step 3: Reverse suffix
        reverse(nums.begin() + i + 1, nums.end());
    }
};