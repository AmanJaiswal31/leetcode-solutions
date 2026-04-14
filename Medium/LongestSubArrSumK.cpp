// Problem: Longest Subarray with Sum K (Positive Integers)
// Link: (common interview problem, not a fixed LeetCode number)
// Difficulty: Medium
// Approach: Sliding Window (Two Pointers) — since all elements are positive,
//           expand window when sum < k, shrink when sum > k,
//           update max length when sum == k.
// Time: O(n) | Space: O(1)

class Solution {
public:
    int longestSubarrayWithSumK(vector<int>& nums, int k) {
        
        int i = 0, j = 0;
        int sum = 0;
        int maxi = 0;

        while (j < nums.size()) {
            sum += nums[j];

            while (sum > k) {
                sum -= nums[i];
                i++;
            }

            if (sum == k) {
                maxi = max(maxi, j - i + 1);
            }

            j++;
        }

        return maxi;
    }
};