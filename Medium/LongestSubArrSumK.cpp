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


// Problem: Subarray Sum Equals K
// Link: https://leetcode.com/problems/subarray-sum-equals-k/
// Difficulty: Medium
// Approach: Prefix Sum + HashMap — store frequency of prefix sums,
//           if (sum - k) exists, add its frequency to count.
// Time: O(n) | Space: O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0;
        int count = 0;

        for (int num : nums) {
            sum += num;

            if (mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }

            mp[sum]++;
        }

        return count;
    }
};