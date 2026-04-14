// Problem: Max Consecutive Ones
// Link: https://leetcode.com/problems/max-consecutive-ones/
// Difficulty: Easy
// Approach: Linear Scan — traverse the array, count consecutive 1s,
//           reset count when 0 is found, track maximum count.
// Time: O(n) | Space: O(1)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int count = 0;
        int maxi = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
                maxi = max(maxi, count);
            } else {
                count = 0;
            }
        }

        return maxi;
    }
};