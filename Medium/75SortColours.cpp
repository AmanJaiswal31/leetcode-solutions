// Problem: Sort Colors (0s, 1s, 2s)
// Link: https://leetcode.com/problems/sort-colors/
// Difficulty: Medium
// Approach: Use three pointers (Dutch National Flag Algorithm)
// int n = nums.size()
// int low = 0, mid = 0, high = n - 1
// while (mid <= high)
//     if nums[mid] == 0 → swap(nums[low], nums[mid]), low++, mid++
//     else if nums[mid] == 1 → mid++
//     else → swap(nums[mid], nums[high]), high--
// Time: O(n) | Space: O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};