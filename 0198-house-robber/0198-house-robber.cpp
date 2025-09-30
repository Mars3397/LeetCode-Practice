/*
Approach
1. 2 choices for ith house: (1) rob ith but not (i-1)th, (2) rob (i-1)th only
2. we need to choose the bigger increasement between 2 choices
3. declare a dp vector where dp[i] is the maximum amount of money can rob from 0 to ith house
4. transitino function: dp[i] = max(dp[i-1], dp[i-2] + nums[i])

Optimization
1. improve from dp vector to 2 variables, since we only need dp[i-1] and dp[i-2]

Analysis
1. time: O(n)
2. space: O(n) -> O(1)
*/


class Solution {
public:
    int rob(vector<int>& nums) {
        // handle nums with size == 1
        int n = nums.size();
        if (n == 1) return nums[0];

        // dp vector initialzation
        vector<int> maxMoney(n);
        maxMoney[0] = nums[0];
        maxMoney[1] = max(nums[1], nums[0]);

        // dp
        for (int i = 2; i < n; ++i) {
            // transition function
            maxMoney[i] = max(maxMoney[i-1], maxMoney[i-2] + nums[i]);
        }

        return maxMoney[n-1];
    }
};