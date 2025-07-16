/*
Approach
1. althrough this problem can be directly calculate usign permutation
2. we can use a 2D DP approach to avoid integer overflow
3. dp[i][j] = dp[i-1][j] + dp[i][j-1]

*/


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // init col 0 to all 1
        for (int i = 0; i < m; ++i)
            dp[i][0] = 1;

        // init row 0 to all 1
        for (int i = 0; i < n; ++i) 
            dp[0][i] = 1;

        // init the rest
        for (int i = 1; i < m; ++i) 
            for (int j = 1; j < n; ++j) 
                dp[i][j] = dp[i-1][j] + dp[i][j-1];

        return dp[m-1][n-1];
    }
};