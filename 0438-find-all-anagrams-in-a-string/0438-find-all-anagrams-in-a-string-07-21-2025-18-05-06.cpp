/*
Approach
1. from the start of s to scan each substr with len = s.size()
2. store the frequency of p in a vector (later will be used to mtach anagrams)


*/


class Solution {
private:
    bool isAnagram(vector<int> &freq, vector<int> cur) {
        for (int i = 0; i < 26; ++i) {
            if (freq[i] != cur[i]) return false;
        }

        return true;
    }

public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};

        vector<int> freq(26, 0);

        // calculate the frequency of each characters in p
        for (char c : p) {
            ++freq[c - 'a'];
        }

        // declare a vector to store current frequency
        vector<int> cur(26, 0);
        vector<int> res;

        // move to first str
        for (int i = 0; i < p.size(); ++i) ++cur[s[i]-'a'];
        if (isAnagram(freq, cur)) res.push_back(0);

        // check each cur string freq and move to next one
        int pn = p.size(), n = s.size() - p.size();
        for (int i = 1; i <= n; ++i) {
            --cur[s[i-1] - 'a'];
            ++cur[s[i+pn-1] - 'a'];

            if (isAnagram(freq, cur)) res.push_back(i);
        }

        return res;
    }
};