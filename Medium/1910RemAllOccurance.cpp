// Problem: Remove All Occurrences of a Substring
// Link: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
// Difficulty: Medium
// Approach: Repeated Find + Erase
// Time: O(n * m) approx (depends on find/erase) | Space: O(1)

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length() > 0 && s.find(part) < s.length()){
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};