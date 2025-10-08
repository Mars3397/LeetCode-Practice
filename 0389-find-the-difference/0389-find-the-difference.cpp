class Solution {
public:
    char findTheDifference(string s, string t) {
        int freqS[26] = {0};
        int freqT[26] = {0};

        for (char c : s) {
            ++freqS[c-'a'];
        }

        for (char c : t) {
            ++freqT[c-'a'];
        }

        for (int i = 0; i < 26; ++i) {
            if (freqS[i] != freqT[i]) {
                return i + 'a';
            }
        }

        return 'a';
    }
};