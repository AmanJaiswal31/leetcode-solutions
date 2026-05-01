// Problem: Peak Index in a Mountain Array
// Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/
// Difficulty: Easy
// Approach: Binary Search
// Time: O(log n) | Space: O(1)

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 0, end = arr.size() - 1;

        // Binary search to find peak element
        while (st < end) {
            int mid = st + (end - st) / 2;

            // If mid is less than next element → we are in increasing slope
            if (arr[mid] < arr[mid + 1]) {
                st = mid + 1;   // move right
            } 
            // Else we are in decreasing slope or at peak
            else {
                end = mid;      // keep mid (could be peak)
            }
        }

        // st == end → peak index
        return st;
    }
};