class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     int n = nums.size();
        
        // Initialize prefix and suffix arrays with size n and default value 1
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        vector<int> ans(n,1);

        // Calculate prefix products
        // prefix[i] contains the product of all elements to the left of i
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        // Calculate suffix products
        // suffix[i] contains the product of all elements to the right of i
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        // Combine prefix and suffix products to get the final answer
        for (int i = 0; i < n; i++) {
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
    }
};






// SC optimised 
// Problem: Product of Array Except Self
// Link: https://leetcode.com/problems/product-of-array-except-self/
// Difficulty: Medium
// Approach: Prefix (in-place) + Suffix variable
// Time: O(n) | Space: O(1) (excluding output array)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // Step 1: store prefix product in ans
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // Step 2: use suffix variable
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = ans[i] * suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};