/*
Approach
1. declare a vector with length = amount + 1 as the DP vector
2. init the coins in DP vector to 1
3. for each non-zero dp[i] -> add up all possible from dp[i-coins]

Analysis
1. time: (n * amount) where n = len(coins)
2. space: O(amount)

*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                if (dp[i - coin] < INT_MAX - dp[i]) {
                    dp[i] += dp[i - coin];
                }
            }
        }


        return dp[amount];
    }
};
