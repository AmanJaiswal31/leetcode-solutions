// Problem: Word Search
// Link: https://leetcode.com/problems/word-search/
// Difficulty: Medium
// Approach: Backtracking (DFS) — start from each cell, match characters recursively
//           in 4 directions, mark visited cells temporarily, backtrack after exploration.
// Time: O(m * n * 4^k) | Space: O(k)

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k) {
        // If all characters are matched
        if (k == word.size()) return true;

        // Boundary and mismatch check
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() 
            || board[i][j] != word[k]) 
            return false;

        char temp = board[i][j];
        board[i][j] = '#'; // mark visited

        // Explore all 4 directions
        bool found = dfs(board, word, i+1, j, k+1) ||
                     dfs(board, word, i-1, j, k+1) ||
                     dfs(board, word, i, j+1, k+1) ||
                     dfs(board, word, i, j-1, k+1);

        board[i][j] = temp; // backtrack
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};