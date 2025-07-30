/*
Approach
1. declare an unordered_map to store the last appear index of each character
2. increase current length until encounter a seen character
3. restart from the last index of the seen character

Analysis
1. time: O(n) where n = len(s)
2. space: O(26 + 26 + 10 + 1) = O(1)
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeenAt;
        int n = s.size(), curStart = 0, maxLen = 0;

        for (int i = 0; i < n; ++i) {
            // record the seen index of character
            if (!lastSeenAt.count(s[i]) || lastSeenAt[s[i]] < curStart) {
                lastSeenAt[s[i]] = i;
                continue;
            }

            // record the max length
            maxLen = max(maxLen, i - curStart);

            // jump to the next index of seen character
            curStart = lastSeenAt[s[i]] + 1;
            lastSeenAt[s[i]] = i;
        }

        // handle string s has no repeat characters
        return max(maxLen, n - curStart);
    }
};