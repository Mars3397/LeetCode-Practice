class Solution {
public:
    int minInsertions(string s) {
        int left = 0, right = 0, n = s.size();
        int insert = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == ')') {
                if (i == n - 1 || s[i+1] != ')') ++insert;
                else ++i;
                ++right;
                if (right > left) {
                    insert += right - left;
                    left = right;
                }
            } else {
                ++left;
            }
        }

        insert += (left - right) * 2;

        return insert;
    }
};