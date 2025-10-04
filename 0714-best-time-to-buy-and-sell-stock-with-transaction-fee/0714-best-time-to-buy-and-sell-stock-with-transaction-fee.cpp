/*
Approach
1. use a dp approach where dp[i] is the max profit we can make at price[i]
2. transition function: dp[i] = find a lower price before it which have max dp[j] + (prices[i] - prices[j] - fee)

Analysis
1. 
*/


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size(), best = -prices[0];
        vector<int> dp(n, 0);

        for (int i = 1; i < n; ++i) {
            if (i > 0) dp[i] = dp[i-1];

            dp[i] = max(dp[i-1], best + prices[i] - fee);

            best = max(best, dp[i] - prices[i]);
        }

        return dp[n-1];
    }
};