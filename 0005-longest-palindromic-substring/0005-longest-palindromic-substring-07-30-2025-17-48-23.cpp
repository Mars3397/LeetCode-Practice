/*
Approach
1. with 2 pointer left and right, expand to the longest palindromic as left and right are center
2. do the above for each index

Analysis
1. time: 
2. space: 
*/


class Solution {
public:
    string longestPalindrome(string s) {
        int left = 0, right = 0, n = s.size();
        int maxLen = 0, maxLeft = 0, maxRight = 0;

        while (left < n || right < n) {
            // expand to longest palindromic
            int l = left, r = right;
            while (0 <= l && r < n && s[l] == s[r]) {
                --l; ++r;
            }

            // record maximum
            int curLen = r - l - 1;
            if (curLen > maxLen) {
                maxLen = curLen;
                maxLeft = l + 1;
                maxRight = r - 1;
            }

            // update centers
            if (left == right) ++right;
            else ++left;
        }

        return s.substr(maxLeft, maxRight - maxLeft + 1);
    }
};