// Problem: Two Sum (Return Values)
//Link: https://leetcode.com/problems/two-sum/
// Difficulty: Easy
// Approach: Two Pointers — Sort the array, then use left & right pointers.
//          If sum < target → move left++, if sum > target → move right--.
//        When sum == target, return the pair of values.
// Time: O(n log n) | Space: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());  // step 1

        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum == target) {
                return {nums[left], nums[right]}; // return values
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }

        return {};
    }
};