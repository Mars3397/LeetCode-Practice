/*
Approach
1. sliding window + freq map
2. make sure in the current window -> the freq of non major element (current size - # major ) <= k
3. keep explore right and slide left when invalid
4. record the maximum

Analysis
1. time: O(n)
2. space: O(1)
*/


class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0};
        int l = 0, r = 0, major = 0; 
        int maxLen = 0, n = s.size();

        while (r < n) {
            // increase freq count and update major
            major = max(major, ++freq[s[r] - 'A']);

            // check for valid or not
            int curLen = r - l + 1;
            while (curLen - major > k) { // shrink to valid
                major = max(major, --freq[s[l] - 'A']);
                ++l; --curLen;
            }

            // record the max valid length
            maxLen = max(maxLen, curLen);

            // mvoe on to next index
            ++r;
        }

        return maxLen;
    }
};