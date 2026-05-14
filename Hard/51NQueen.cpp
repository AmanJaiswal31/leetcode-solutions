// Problem: N-Queens
// Link: https://leetcode.com/problems/n-queens/
// Difficulty: Hard
// Approach: Backtracking
// Time: Exponential | Space: O(n^2)

class Solution {
public:
    vector<vector<string>> result;

    // Check whether queen can be placed safely
    bool isSafe(int row, int col, vector<string>& board, int n) {

        // Check horizontal
        for (int j = 0; j < n; j++) {
            if (board[row][j] == 'Q') {
                return false;
            }
        }

        // Check vertical
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Check upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Check upper-right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    // Backtracking function
    void solve(int row, vector<string>& board, int n) {

        // All queens placed
        if (row == n) {
            result.push_back(board);
            return;
        }

        // Try placing queen in every column
        for (int col = 0; col < n; col++) {

            if (isSafe(row, col, board, n)) {

                // Place queen
                board[row][col] = 'Q';

                // Recurse for next row
                solve(row + 1, board, n);

                // Backtrack
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        // Create empty board
        vector<string> board(n, string(n, '.'));

        solve(0, board, n);

        return result;
    }
};