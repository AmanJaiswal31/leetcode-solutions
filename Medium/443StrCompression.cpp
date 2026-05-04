// Problem: String Compression
// Link: https://leetcode.com/problems/string-compression/
// Difficulty: Medium
// Approach: Two Pointers (Read + Write)
// Time: O(n) | Space: O(1)

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;          // read pointer
        int idx = 0;        // write pointer

        while (i < n) {
            char ch = chars[i];
            int count = 0;

            // count occurrences of current character
            while (i < n && chars[i] == ch) {
                i++;
                count++;
            }

            // write character
            chars[idx++] = ch;

            // write count if > 1
            if (count > 1) {
                string cnt = to_string(count);
                for (char c : cnt) {
                    chars[idx++] = c;
                }
            }
        }

        return idx; // new length
    }
};