// Problem: Search a 2D Matrix II
// Link: https://leetcode.com/problems/search-a-2d-matrix-ii/
// Difficulty: Medium
// Approach: Staircase Search (Top-Right Corner)
// Time: O(m + n) | Space: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();

        // Start from top-right corner
        int r = 0, c = n - 1;

        while (r < m && c >= 0) {

            // Found target
            if (target == mat[r][c]) {
                return true;
            } 
            // Move left
            else if (target < mat[r][c]) {
                c--;
            } 
            // Move down
            else {
                r++;
            }
        }

        return false;
    }
};