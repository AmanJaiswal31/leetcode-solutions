// Problem: Container With Most Water
// Link: https://leetcode.com/problems/container-with-most-water/
// Difficulty: Medium
// Approach: Two pointers
// Time: O(n) | Space: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int lp = 0;
        int rp = height.size() - 1;

        while (lp < rp) {
            int w = rp - lp;
            int ht = min(height[lp], height[rp]);
            int currWater = w * ht;

            maxWater = max(maxWater, currWater);

            // move pointer with smaller height
            (height[lp] < height[rp]) ? lp++ : rp--;
        }

        return maxWater;
    }
};