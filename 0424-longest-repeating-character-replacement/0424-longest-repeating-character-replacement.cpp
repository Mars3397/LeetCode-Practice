/*
Approach
1. maintain a sliding window to make sure: len - # max freq char <= k (can be replaced)
2. try to extend right as much as possible
3. move left until window is valid if extending right cause an invalid window

Analysis
1. O(n) where n = s.size()
2. space: O(1)
*/


class Solution {
private: 
    int getMaxFreq(vector<int> &freq) {
        int maxFreq = 0;

        for (int i = 0; i < 26; ++i) {
            maxFreq = max(maxFreq, freq[i]);
        }

        return maxFreq;
    }

public:
    int characterReplacement(string s, int k) {
        int maxLen = 0, n = s.size();
        vector<int> freq(26, 0);

        for (int l = 0, r = 0; r < n; ++r) {
            ++freq[s[r] - 'A'];

            // mvoe left pointer to make len - # max freq char <= k
            while ((r-l+1) - getMaxFreq(freq) > k) {
                --freq[s[l++] - 'A'];
            }

            // record current length
            maxLen = max(maxLen, r-l+1);
        }

        return maxLen;
    }
};