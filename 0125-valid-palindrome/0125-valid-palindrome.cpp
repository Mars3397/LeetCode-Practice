/*
Approach
1. prune the string: upper to lower and remove all non-alphanumeric
2. check palindrome

Analysis
1. time: O(n) where n = s.size()
2. space: O(1)
*/

class Solution {
private:
    void prune(string &s) {
        int write = 0;
        for (int read = 0; read < s.size(); ++read) {
            if (isalnum(s[read])) s[write++] = tolower(s[read]);
        }

        s.resize(write);
    }

public:
    bool isPalindrome(string s) {
        prune(s);

        int l = 0, r = s.size()-1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            ++l; --r;
        }

        return true;
    }
};