/*
Approach
1. DP => dp[i] is the minimum steps from 0 to i
2. transition function: for all j < i: find min(dp[j] + 1) where can jump from j to i
3. return nums.size()-1

Analysis
1. time: O
*/


class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> minSteps(n, INT_MAX);
        minSteps[0] = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (j + nums[j] >= i) {
                    minSteps[i] = min(minSteps[i], minSteps[j] + 1);
                }
            }
        }

        return minSteps[n-1];
    }
};