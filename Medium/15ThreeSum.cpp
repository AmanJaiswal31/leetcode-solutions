// Problem: 3Sum
// Link: https://leetcode.com/problems/3sum/
// Difficulty: Medium
// Approach: Sorting + Two Pointers
// Time: O(n^2) | Space: O(1) (excluding output array)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;
        int n = nums.size();

        // Sort array
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {

            // Skip duplicate elements
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1;
            int k = n - 1;

            // Two pointer search
            while (j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                // Triplet found
                if (sum == 0) {

                    ans.push_back({nums[i], nums[j], nums[k]});

                    j++;
                    k--;

                    // Skip duplicates
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }

                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }

                // Need bigger sum
                else if (sum < 0) {
                    j++;
                }

                // Need smaller sum
                else {
                    k--;
                }
            }
        }

        return ans;
    }
};