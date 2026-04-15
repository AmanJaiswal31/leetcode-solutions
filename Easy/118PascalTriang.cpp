// Problem: Pascal's Triangle
// Link: https://leetcode.com/problems/pascals-triangle/
// Difficulty: Easy
// Approach: Simulation — build each row using previous row,
//           first and last elements are always 1, inner elements
//           are sum of two elements from previous row.
// Time: O(n^2) | Space: O(n^2)

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);

            for (int j = 1; j < i; j++) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            triangle.push_back(row);
        }

        return triangle;
    }
};