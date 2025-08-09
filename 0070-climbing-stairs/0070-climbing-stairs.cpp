/*
Approach
1. dp approach
2. dp[i] = dp[i-1] + dp[i-2] and dp[0] = 1, dp[1] = 1

Analysis
1. time: O(n)
2. space: O(n)
*/


class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0] = 1; dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};