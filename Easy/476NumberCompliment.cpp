// Problem: Number Complement
// Link: https://leetcode.com/problems/number-complement/
// Difficulty: Easy
// Approach: Bit Manipulation (Mask)
// Time: O(1) | Space: O(1)

class Solution {
public:
    int findComplement(int num) {

        int mask = num;

        // Create mask with all bits set to 1
        mask |= (mask >> 1);
        mask |= (mask >> 2);
        mask |= (mask >> 4);
        mask |= (mask >> 8);
        mask |= (mask >> 16);

        // XOR flips bits
        return num ^ mask;
    }
};