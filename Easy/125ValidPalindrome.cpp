// Problem: Valid Palindrome
// Link: https://leetcode.com/problems/valid-palindrome/
// Difficulty: Easy
// Approach: Two Pointers + Alphanumeric Check
// Time: O(n) | Space: O(1)

class Solution {
public:
    // Check if character is alphanumeric
    bool isAlphaNum(char ch) {
        if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')) {
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        int st = 0, end = s.length() - 1;

        while (st < end) {

            // Skip non-alphanumeric from left
            if (!isAlphaNum(s[st])) {
                st++;
                continue;
            }

            // Skip non-alphanumeric from right
            if (!isAlphaNum(s[end])) {
                end--;
                continue;
            }

            // Compare characters (case-insensitive)
            if (tolower(s[st]) != tolower(s[end])) {
                return false;
            }

            st++;
            end--;
        }

        return true;
    }
};