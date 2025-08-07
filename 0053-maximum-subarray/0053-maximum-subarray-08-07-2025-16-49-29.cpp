/*
Approach
1. key point: when current sum become 0 -> restart from the next one
2. iterate through nums and record max sum in sub array

Analysis
1. time: O(n) where n = nums.size()
2. space: O(1)
*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, curSum = 0;

        for (int num : nums) {
            curSum += num;
            maxSum = max(maxSum, curSum);

            // restart if sum become negative (will pose a negative effect to sum afterwards)
            if (curSum < 0) curSum = 0;
        }

        return maxSum;
    }
};