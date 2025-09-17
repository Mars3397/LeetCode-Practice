/*
Approach
1. first check the length of 2 string is the same or not, if not -> return false
2. compare the character frequency of 2 string, if not match -> return false

Analysis
1. time: O(m + n) where m = s.size() and n = t.size()
2. space: O(26) = O(1) (for only lowercase English letters)
*/


class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.size(), n = t.size();
        if (m != n) return false; // check the length equal or not

        int freq[26] = { 0 };
        for (int i = 0; i < m; ++i) {
            ++freq[s[i] - 'a']; // +1 for the frequency of letter
        }

        for (int i = 0; i < n; ++i) {
            // no more available letters -> frequency not match
            if (--freq[t[i] - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};