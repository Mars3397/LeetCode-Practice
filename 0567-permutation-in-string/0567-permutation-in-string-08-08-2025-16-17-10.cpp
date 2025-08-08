/*
Approach
1. calculate the frequency of s1
2. try to match the freqency for each substring start with a letter in s2

Analysis
1. time: O(n * m) where n = s1.size() and m = s2.size() 
2. space: O(m) where and m = s2.size() 
*/

class Solution {
private:
    int N1, N2;

    bool match(vector<int> f, const string &s2, int start) {
        for (int i = 0; i < N1; ++i) {
            int idx = s2[start+i]-'a';
            --f[idx];

            if (f[idx] < 0) return false;
        }

        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        N1 = s1.size(), N2 = s2.size();
        if (N1 > N2) return false;

        vector<int> freq(26, 0);
        for (char c : s1) {
            ++freq[c-'a'];
        }

        int end = N2 - N1;
        for (int i = 0; i <= N2 - N1; ++i) {
            if (freq[s2[i]-'a'] && match(freq, s2, i)) return true;
        }

        return false;
    }
};