/*
Approach
1. use a 2D DP approach to solve this problem (can be optimize to 1D)
2. definition: dp[i][j] = LCS in text1[0...i] and text2[0...j]
3. transition function: dp[i][j] = dp[i-1][j-1] + 1 if text1[i] == text2[j] otherwise = max(dp[i-1][j], dp[i][j-1])
4. return dp[text1.size()-1][text2.size()-1]

Analysis
1. time: O(n1 * n2) where n1 = text1.size(), n2 = text2.size()
2. space: O(n1 * n2) where n1 = text1.size(), n2 = text2.size()
*/


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        // dp
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n1][n2];
    }
};