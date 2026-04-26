// Problem: Longest Consecutive Sequence
// Link: https://leetcode.com/problems/longest-consecutive-sequence/
// Difficulty: Medium
// Approach: Use unordered_set to achieve O(n) time
// Time: O(n) | Space: O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // 🔹 Step 1: Insert all elements into unordered_set
        // This removes duplicates and allows O(1) lookup
        unordered_set<int> s(nums.begin(), nums.end());

        // 🔹 Variable to store the maximum length of consecutive sequence
        int longest = 0;

        // 🔹 Step 2: Iterate through each unique element
        for (int num : s) {

            // 🔥 Step 3: Check if current number is the START of a sequence
            // Condition: (num - 1) should NOT exist in the set
            // If it exists, then this is NOT the starting point
            if (s.find(num - 1) == s.end()) {

                // 🔹 Initialize current number and count
                int curr = num;   // current element in sequence
                int count = 1;    // sequence length starts from 1

                // 🔹 Step 4: Expand the sequence forward
                // Keep checking if next consecutive element exists
                while (s.find(curr + 1) != s.end()) {
                    curr++;       // move to next number
                    count++;      // increase sequence length
                }

                // 🔹 Step 5: Update the maximum length found so far
                longest = max(longest, count);
            }
        }

        // 🔹 Step 6: Return the longest consecutive sequence length
        return longest;
    }
};