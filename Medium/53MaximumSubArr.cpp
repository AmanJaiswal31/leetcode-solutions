// Problem: Maximum Subarray
// Link: https://leetcode.com/problems/maximum-subarray/
// Difficulty: Medium
// Approach: Kadane’s Algorithm — 
//           keep a running sum, reset if it becomes negative,
//           and track the maximum sum seen so far.
// Time: O(n) | Space: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum = 0;
        int maxsum = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            currsum += nums[i];

            if (currsum > maxsum) {
                maxsum = currsum;
            }

            if (currsum < 0) {
                currsum = 0;
            }
        }

        return maxsum;
    }
};