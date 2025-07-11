/*
Approach
1. use a dynamic approach to solve this problem
2. declare dp vector where do[i] = can we find elements sum up to i or not

Analysis
1. time: O(n * t) where n = number of numbers in nums and t = sum(nums)
2. space: O(t) where t = sum(nums)
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        // early return: with odd total sum, we can't divide into 2 equal sets
        if (sum % 2 == 1) return false; 
        int target = sum / 2;
        vector<bool> dp(target+1, false);
        dp[0] = true;

        for (int num : nums) {
            // from target to num to prevent duplicate use of num
            for (int i = target; i >= num; --i) {
                // eg. dp[11] = true if we find 11 or 6 (num=5)
                dp[i] = dp[i] || dp[i - num];
            }
        }

        return dp[target];
    }
};