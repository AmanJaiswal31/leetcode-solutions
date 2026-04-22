// Problem: Pow(x, n)
// Link: https://leetcode.com/problems/powx-n/
// Difficulty: Medium
// Approach: Binary Exponentiation with edge case handling
// Time: O(log n) | Space: O(1)

class Solution {
public:
    double myPow(double x, int n) {
        
        // 🔹 Edge cases
        if (n == 0) return 1.0;
        if (x == 0) return 0.0;
        if (x == 1) return 1.0;
        if (x == -1) {
            if (n % 2 == 0) return 1.0;
            else return -1.0;
        }

        long long binForm = n;  // handle INT_MIN

        // 🔹 Handle negative power
        if (binForm < 0) {
            x = 1 / x;
            binForm = -binForm;
        }

        double ans = 1.0;

        // 🔹 Binary exponentiation
        while (binForm > 0) {
            if (binForm % 2 == 1) {
                ans *= x;
            }
            x *= x;
            binForm /= 2;
        }

        return ans;
    }
};