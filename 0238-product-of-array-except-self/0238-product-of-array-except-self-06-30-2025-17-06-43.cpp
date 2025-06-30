/*
Approach
1. declare vector to store output and help calculate result
2. iterate forward and backward to calculate the product

Analysis
1. time: O(n) where n = nums.size()
2. space: O(1)
*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        int prod = 1;

        // forward
        for (int i = 0; i < n; ++i) {
            res[i] *= prod;
            prod *= nums[i];
        }

        // reset prod and iterate backward
        prod = 1;
        for (int i = n-1; i >= 0; --i) {
            res[i] *= prod;
            prod *= nums[i];
        }

        return res;
    }
};