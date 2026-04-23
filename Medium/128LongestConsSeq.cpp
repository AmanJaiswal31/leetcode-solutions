// Problem: Longest Consecutive Sequence
// Link: https://leetcode.com/problems/longest-consecutive-sequence/
// Difficulty: Medium
// Approach: Use unordered_set to check sequence starts
// Time: O(n) | Space: O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for (int num : s) {
            // start of sequence
            if (s.find(num - 1) == s.end()) {
                int curr = num;
                int count = 1;

                while (s.find(curr + 1) != s.end()) {
                    curr++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};