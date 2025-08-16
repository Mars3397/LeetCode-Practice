/*
Approach
1. record the current minimum buy price in a variable
2. iterate through prices to store max profit (price - current min price) into maxReward

Analysis
1. time: O(n) where n = prices.size()
2. space: O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, maxReward = 0;
        
        for (int price : prices) {
            maxReward = max(maxReward, price - minPrice);
            minPrice = min(minPrice, price);
        }

        return maxReward;
    }
};