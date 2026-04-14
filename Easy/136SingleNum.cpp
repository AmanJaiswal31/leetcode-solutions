// Problem: Single Number
// Link: https://leetcode.com/problems/single-number/
// Difficulty: Easy
// Approach: XOR — XOR all elements, duplicates cancel out (a ^ a = 0),
//           remaining value is the element that appears once.
// Time: O(n) | Space: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int result = 0;

        for (int i = 0; i < nums.size(); i++) {
            result ^= nums[i];
        }

        return result;
    }
};