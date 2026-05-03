// Problem: Allocate Books
// Platform: GFG / InterviewBit (Similar to LeetCode 410 - Split Array Largest Sum)
// Difficulty: Hard
// Approach: Binary Search on Answer
// Time: O(n log(sum)) | Space: O(1)

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Check if allocation is possible with given maxAllowedPages
bool isValid(vector<int> &arr, int n, int m, int maxAllowedPages) {
    int students = 1, pages = 0;

    for (int i = 0; i < n; i++) {
        // If a single book exceeds limit → not possible
        if (arr[i] > maxAllowedPages) {
            return false;
        }

        // Assign book to current student
        if (pages + arr[i] <= maxAllowedPages) {
            pages += arr[i];
        } 
        // Allocate to next student
        else {
            students++;
            pages = arr[i];
        }
    }

    return students <= m;
}

int allocateBooks(vector<int> &arr, int n, int m) {
    // More students than books → invalid
    if (m > n) {
        return -1;
    }

    // Lower bound = max element, Upper bound = total sum
    int st = *max_element(arr.begin(), arr.end());
    int end = accumulate(arr.begin(), arr.end(), 0);

    int ans = -1;

    // Binary search on answer
    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (isValid(arr, n, m, mid)) {
            ans = mid;
            end = mid - 1;  // try smaller maximum
        } else {
            st = mid + 1;   // increase limit
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {2, 1, 3, 4};
    int n = 4, m = 2;

    cout << allocateBooks(arr, n, m) << endl;

    return 0;
}