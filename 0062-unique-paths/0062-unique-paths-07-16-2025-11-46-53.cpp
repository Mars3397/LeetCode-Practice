/*
Approach
1. althrough this problem can be directly calculate usign permutation
2. we can use a 2D DP approach to avoid integer overflow
3. dp[i][j] = dp[i-1][j] + dp[i][j-1]

Analysis
1. time: O(m*n)
2. space: O(m*n)
*/


class Solution {
public:
    int uniquePaths(int m, int n) {
        int smaller = min(m-1, n-1), total = m+n-1;
        long long ans = 1;

        for (int i = 1; i <= smaller; ++i) {
            ans = ans * (total - i) / i;
        }

        return ans;
    }
};