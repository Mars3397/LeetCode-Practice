/*
Approach
1. just check every prices[i] and prices[i+1]
2. if prices[i+1] > prices[i] -> buy on ith day and sell at (i+1)th day

Analysis
1. time: O(n) where n = prices.size()
2. space: O(1)
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int end = prices.size() - 1, profit = 0;
        for (int i = 0; i < end; ++i) {
            if (prices[i] < prices[i+1]) {
                profit += prices[i+1] - prices[i];
            }
        }

        return profit;
    }
};