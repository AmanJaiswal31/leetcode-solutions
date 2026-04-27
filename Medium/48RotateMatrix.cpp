// Problem: Rotate Image
// Link: https://leetcode.com/problems/rotate-image/
// Difficulty: Medium
// Approach: Transpose + Reverse rows
// Time: O(n^2) | Space: O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // 🔹 Step 1: Transpose (swap across diagonal)
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 🔹 Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};