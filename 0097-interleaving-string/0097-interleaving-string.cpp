/*
Approach
1. use a 2D DP approach to solve this problem
2. dp[i][j] = wether s3[0...i+j-1] isInterleave by s1[0...i-1] and s2[0...j-1]
3. transition:  if dp[i-1][j] -> check s3[i+j-1] == s1[i-1]
                if dp[i][j-1] -> check s3[i+j-1] == s2[j-1]
4. if a row is all false -> return false (a char in s3 exists neither in s1 nor s2)
4, return dp[n1][n2]

Example: 
   _  d  b  b  c  a
_  1  0  0  0  0  0
a  1  0  0  0  0  0
a  1  1  1  0  0  0
b  0  1  1  0  0  0
c  0  0  1  1  1  1
c  0  0  0  1  0  1

Analysis
1. time: O(n1 * n2) where n1 = s1.size() and n2 = s2.size()
2. space: O(n1 * n2) (can be further optimized to O(min(n1, n2)))
*/


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n3 != n1 + n2) return false;

        vector<vector<bool>> dp(n1+1, vector<bool>(n2+1, false));
        dp[0][0] = true;

        // init
        for (int i = 1; i <= n1; ++i) {
            if (s3[i-1] == s1[i-1]) dp[i][0] = true;
            else break;
        }

        for (int j = 1; j <= n2; ++j) {
            if (s3[j-1] == s2[j-1]) dp[0][j] = true;
            else break;
        }

        // transit
        for (int i  = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (dp[i-1][j] && s3[i+j-1] == s1[i-1]) {
                    dp[i][j] = true;
                    continue;
                }

                if (dp[i][j-1] && s3[i+j-1] == s2[j-1]) {
                    dp[i][j] = true;
                }
            }
        }

        return dp[n1][n2];
    }
};