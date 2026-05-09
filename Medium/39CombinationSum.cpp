// Problem: Combination Sum
// Link: https://leetcode.com/problems/combination-sum/
// Difficulty: Medium
// Approach: Backtracking
// Time: Exponential | Space: O(target) recursion stack

class Solution {
public:

    void solve(vector<int>& candidates, int target, int idx,
               vector<int>& temp, vector<vector<int>>& ans) {

        // Combination found
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        // Out of bounds or target negative
        if (idx >= candidates.size() || target < 0) {
            return;
        }

        // Include current element
        temp.push_back(candidates[idx]);

        // Same index because element can be reused
        solve(candidates, target - candidates[idx], idx, temp, ans);

        // Backtrack
        temp.pop_back();

        // Exclude current element
        solve(candidates, target, idx + 1, temp, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> temp;

        solve(candidates, target, 0, temp, ans);

        return ans;
    }
};