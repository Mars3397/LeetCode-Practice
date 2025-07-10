/*
Approach
1. we can use a dp approach to solve this problem
2. declare a boolean vector to store whether from 0 to i can be formed
*/


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1);
        dp[0] = true; // start from first index

        for (int i = 1; i <= n; ++i) {
            if (!dp[i-1]) continue;
            for (string &word : wordDict) {
                int size = word.size(); bool matched = true;
                for (int j = 0; j < size && i+j <= n; ++j) {
                    if (s[i+j-1] != word[j]) {
                        matched = false;
                        break;
                    }
                }

                if (matched) dp[i+size-1] = true;
            }
        }

        return dp[n];
    }
};