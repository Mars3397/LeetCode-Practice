/*
Approach
1. try to expand palindrome from each index
2. count + 1 when expand success

Analysis
1. time: O(n^2) where n = s.size()
2. space: O(1)
*/

class Solution {
private: 
    int N, count = 0;

    void expand(int l, int r, string &s) {
        while (l >= 0 && r < N && s[l--] == s[r++]) {
            ++count;
        }
    }

public:
    int countSubstrings(string s) {
        N = s.size();

        for (int i = 0; i < N; ++i) {
            expand(i, i, s);
            expand(i, i+1, s);
        }

        return count;
    }
};