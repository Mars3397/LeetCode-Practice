/*
Approach
1. use a DP approach
2. dp[i] = s[0...i] in can be formed with words in dict or not

Analysis
1. time: 
2. space: 
*/


class Solution {
private:
    bool matched(string &target, string &pattern) {
        if (pattern.size() > target.size()) return false;

        for (int i = 0; i < pattern.size(); ++i) {
            if (target[i] != pattern[i]) return false;
        }

        return true;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n, false);
        unordered_set<string> uset;

        for (string &w : wordDict) {
            if (!dp[w.size()-1]) dp[w.size()-1] = matched(s, w);
            uset.insert(w);
        }

        for (int i = 1; i < n; ++i) {
            if (dp[i]) continue;

            for (int j = 0; j < i; ++j) {
                if (dp[j] && uset.count(s.substr(j+1, i-j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n-1];
    }
};