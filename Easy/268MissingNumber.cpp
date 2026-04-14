// Problem: Missing Number
// Link: https://leetcode.com/problems/missing-number/
// Difficulty: Easy
// Approach: Math (Sum Formula) — compute expected sum of first n natural numbers,
//           subtract actual array sum to get the missing number.
// Time: O(n) | Space: O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;
        
        for (int num : nums) {
            actualSum += num;
        }
        
        return expectedSum - actualSum;
    }
};