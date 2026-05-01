// Problem: Search in Rotated Sorted Array
// Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
// Difficulty: Medium
// Approach: Modified Binary Search
// Time: O(log n) | Space: O(1)

class Solution {
public:
    int search( vector<int>& A, int tar) {
        int st = 0, end = A.size() - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            // If target found
            if (A[mid] == tar) {
                return mid;
            }

            // Left half is sorted
            if (A[st] <= A[mid]) {
                if (A[st] <= tar && tar <= A[mid]) {
                    end = mid - 1;   // target lies in left sorted half
                } else {
                    st = mid + 1;    // search right half
                }
            }
            // Right half is sorted
            else {
                if (A[mid] <= tar && tar <= A[end]) {
                    st = mid + 1;    // target lies in right sorted half
                } else {
                    end = mid - 1;   // search left half
                }
            }
        }

        return -1;
    }
};