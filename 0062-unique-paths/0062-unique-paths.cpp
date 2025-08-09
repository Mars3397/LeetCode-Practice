/*
Approach
1. this can be solved by math approach or dp approach
2. math: ans = (m+n)!/m!n!
3. dp: dp[i][j] = dp[i-1][j] + dp[i][j-1] (can be optimized to 1D)

Analysis (math)
1. time: O(min(m, n))
2. space: O(1)
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        int smaller = min(m-1, n-1), bigger = max(m-1, n-1);

        for (int i = 1; i <= smaller; ++i) {
            ans *= (bigger + i);
            ans /= i;
        }

        return ans;
    }
};