// Problem: Number Complement
// Link: https://leetcode.com/problems/number-complement/
// Difficulty: Easy
// Approach: Bit Manipulation (Mask)
// Time: O(1) | Space: O(1)

class Solution {
public:
    int findComplement(int num) {

        int numbits  = (int) (log2(num))+1;
long long  mask = (1LL<< numbits)-1;        //1LL  means:  1 as a long long integer

        
        return num ^ mask;
    }
};