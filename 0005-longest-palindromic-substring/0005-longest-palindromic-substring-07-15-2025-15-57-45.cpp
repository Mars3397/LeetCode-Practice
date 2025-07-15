/*
Approach
1. start from each s[i] as the middle of a palindromic to find the longest one
2. handle odd length and even length differently

Analysis
1. time: O(n*2) where n = s.size()
2. space: O(1)
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int left = 0, right = 0, n = s.size();
        int maxLen = 0; string longest;
        bool oddLen = true;

        while (left < n || right < n) {
            int halfLen = 0, l = left, r = right;
            while (l >= 0 && r < n && s[l] == s[r]) {
                ++halfLen; --l; ++r;
            }
            
            int fullLen;
            if (oddLen) {
                fullLen = halfLen * 2 - 1;
                ++right;
            } else {
                fullLen = halfLen * 2;
                ++left;
            }

            if (fullLen > maxLen) {
                maxLen = fullLen;
                longest = s.substr(l+1, fullLen);
            }

            oddLen = !oddLen;
        }

        return longest;
    }
};