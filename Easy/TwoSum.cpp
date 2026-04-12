// Problem: Two Sum
// Link: https://leetcode.com/problems/two-sum/
// Difficulty: Easy
// Approach: One Pass HashMap — for each number, check if its
//           complement (target - num) already exists in the map.
//           If yes, return both indices. If no, store current number.
// Time: O(n) | Space: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int needed = target - nums[i];

            if (mp.find(needed) != mp.end()) {
                return {mp[needed], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};