// Problem: Peak Index in a Mountain Array
// Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/
// Difficulty: Easy
// Approach: Binary Search
// Time: O(log n) | Space: O(1)

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 1, end = arr.size() - 2;

        // Binary search to find peak element
        while (st <= end) {
            int mid = st + (end - st) / 2;

            // If mid is less than next element → we are in increasing slope
            if (arr[mid-1] < arr[mid] && arr[mid + 1]< arr[mid ]) {
return mid;
            }
            else if (arr[mid-1] < arr[mid]){
                  st = mid + 1;   // move right

            }


              
            
            // Else we are in decreasing slope or at peak
            else {
                end = mid-1;      // keep mid (could be peak)
            }
        }

         return -1;
    }
};