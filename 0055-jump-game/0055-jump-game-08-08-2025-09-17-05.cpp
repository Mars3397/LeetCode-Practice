/*
Approach
1. use a dp vector to store whether each number can be reached

Analysis
1. time: O(n^2) where n = nums.size()
2. space: O(n) where n = nums.size()
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[0] = true;

        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (dp[j] && j + nums[j] >= i) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n-1];
    }
};