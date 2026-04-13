// Problem: Reverse Integer
// Link: https://leetcode.com/problems/reverse-integer/
// Difficulty: Medium
// Approach: Math + Overflow Check — extract digits one by one using
//           modulo, build reversed number. Use long long to safely
//           detect 32-bit integer overflow before returning.
// Time: O(log n) | Space: O(1)

class Solution {
public:
    int reverse(int x) {
        long long rev = 0;

        while (x != 0) {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x = x / 10;
        }

        if (rev > INT_MAX || rev < INT_MIN)
            return 0;

        return (int)rev;
    }
};