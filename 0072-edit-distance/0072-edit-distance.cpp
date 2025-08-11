/*
Approach
1. use a 2D DP approach: dp[i][j] = minimum steps took from word1[0..i-1] to word2[0...j-1]
2. transition:  if word1[i] == word2[j] -> dp[i][j] = dp[i-1][j-1]
                else dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
                                    replace       delete      insert

Analysis
1. time: O(m * n) where m = word1.size() and n = word2.size()
2. space: O(m * n) where m = word1.size() and n = word2.size()
*/


class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size()+1, n = word2.size()+1;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            dp[i][0] = i;
        }

        for (int i = 0; i < n; ++i) {
            dp[0][i] = i;
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]) + 1;
                }
            }
        }

        return dp[m-1][n-1];
    }
};