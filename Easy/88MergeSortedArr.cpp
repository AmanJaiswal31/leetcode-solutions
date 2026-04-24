// Problem: Merge Sorted Array
// Link: https://leetcode.com/problems/merge-sorted-array/
// Difficulty: Easy
// Approach: Start filling from the end (3 pointers)
// Time: O(m + n) | Space: O(1)

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i = m - 1;       // last element in A
        int j = n - 1;       // last element in B
        int idx = m + n - 1; // last position in A

        // 🔹 Merge from back
        while (i >= 0 && j >= 0) {
            if (A[i] > B[j]) {
                A[idx--] = A[i--];
            } else {
                A[idx--] = B[j--];
            }
        }

        // 🔹 Copy remaining B elements (if any)
        while (j >= 0) {
            A[idx--] = B[j--];
        }
    }
};