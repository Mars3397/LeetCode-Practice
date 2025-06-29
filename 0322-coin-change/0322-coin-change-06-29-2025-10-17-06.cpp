/*
Approach
1. use a dp approach to solve this problem
2. dp[i] will be the fewest number of coins that you need to make up amount i
3. start from coin in coins to amount

Analysis
1. time: O(amount * c) where c = total number of coins
2. space: O(amount)
*/


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX); 

        dp[0] = 0;

        for (int i = 0; i < amount; ++i) {
            if (dp[i] != INT_MAX) { // can make up
                for (int coin : coins) {
                    if (i <= amount - coin) {
                        dp[i+coin] = min(dp[i+coin], dp[i]+1);
                    }
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};