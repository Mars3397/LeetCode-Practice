class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (t.size() < s.size()) return false;

        int s_idx = 0;

        for (int i = 0; i < t.size() && s_idx < s.size(); ++i) {
            if (t[i] == s[s_idx]) ++s_idx;
        }

        return s_idx == s.size();
    }
};