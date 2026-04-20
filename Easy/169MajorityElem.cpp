// Problem: Majority Element
// Link: https://leetcode.com/problems/majority-element/
// Difficulty: Easy
// Approach: Boyer-Moore Voting Algorithm — 
//           maintain a candidate and a counter.
//           If counter becomes 0, pick new candidate.
//           Increase count if same element, else decrease.
// Time: O(n) | Space: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0, ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (freq == 0) {
                ans = nums[i];
            }

            if (nums[i] == ans) {
                freq++;
            } else {
                freq--;
            }
        }

        return ans;
    }
};