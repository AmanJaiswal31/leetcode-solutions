// Problem: Leaders in an Array
// Difficulty: Easy
// Approach: Traverse from right and track maximum element
// Time: O(n) | Space: O(n)

class Solution {
public:
    vector<int> leaders(int a[], int n) {
        vector<int> ans;
        int maxi = INT_MIN;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] >= maxi) {
                ans.push_back(a[i]);
            }
            maxi = max(maxi, a[i]);
        }

        // Reverse to maintain original order
        reverse(ans.begin(), ans.end());

        return ans;
    }
};