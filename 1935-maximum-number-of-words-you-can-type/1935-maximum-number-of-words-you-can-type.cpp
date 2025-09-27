/*
Approach
1. maintain a bool[26] array as broken letters == true
2. iterate through text to check wether any word has broken letters

Analysis
1. time: O(n) where n = text.size()
2. space: O(26) = O(1)
*/


class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        // construct broken array
        bool broken[26] = { false };
        for (char c : brokenLetters) {
            broken[c - 'a'] = true;
        }

        int n = text.size(), cnt = 0;
        bool lastGood = true;
        for (int i = 0; i < n; ++i) {
            if (text[i] == ' ') { // word seperator
                ++cnt;
            } else if (broken[text[i] - 'a']) { // a broken letter -> restart from next word
                while (i < n && text[i] != ' ') {
                    ++i;
                }
                lastGood = false;
            } else {
                lastGood = true;
            }
        }

        return lastGood ? cnt + 1 : cnt;
    }
};