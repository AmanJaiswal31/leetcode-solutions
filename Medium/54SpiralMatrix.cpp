// Problem: Spiral Matrix
// Approach: 4 boundaries + edge case handling
// Time: O(m*n) | Space: O(1)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int m = matrix.size();
        int n = matrix[0].size();

        int srow = 0, erow = m - 1;
        int scol = 0, ecol = n - 1;

        while (srow <= erow && scol <= ecol) {

            // 🔹 1. Top row
            for (int j = scol; j <= ecol; j++) {
                ans.push_back(matrix[srow][j]);
            }
            srow++;

            // 🔹 2. Right column
            for (int i = srow; i <= erow; i++) {
                ans.push_back(matrix[i][ecol]);
            }
            ecol--;

            // 🔴 Edge case: only one row left
            if (srow > erow) break;

            // 🔹 3. Bottom row
            for (int j = ecol; j >= scol; j--) {
                ans.push_back(matrix[erow][j]);
            }
            erow--;

            // 🔴 Edge case: only one column left
            if (scol > ecol) break;

            // 🔹 4. Left column
            for (int i = erow; i >= srow; i--) {
                ans.push_back(matrix[i][scol]);
            }
            scol++;
        }

        return ans;
    }
};