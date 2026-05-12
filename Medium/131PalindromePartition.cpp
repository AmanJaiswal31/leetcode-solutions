// Problem: Palindrome Partitioning
// Link: https://leetcode.com/problems/palindrome-partitioning/
// Difficulty: Medium
// Approach: Backtracking
// Time: Exponential | Space: O(n) recursion stack

class Solution {
public:

    // Check if substring is palindrome
    bool isPalindrome(string &s, int st, int end) {

        while (st < end) {

            if (s[st] != s[end]) {
                return false;
            }

            st++;
            end--;
        }

        return true;
    }

    // Backtracking function
    void solve(string &s, int idx,
               vector<string> &temp,
               vector<vector<string>> &ans) {

        // Partition completed
        if (idx == s.length()) {
            ans.push_back(temp);
            return;
        }

        // Generate all substrings starting from idx
        for (int i = idx; i < s.length(); i++) {

            // Check palindrome
            if (isPalindrome(s, idx, i)) {

                // Choose substring
                temp.push_back(s.substr(idx, i - idx + 1));

                // Recurse for remaining string
                solve(s, i + 1, temp, ans);

                // Backtrack
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> temp;

        solve(s, 0, temp, ans);

        return ans;
    }
};