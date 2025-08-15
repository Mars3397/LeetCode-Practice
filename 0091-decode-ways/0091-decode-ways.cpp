/*
Approach
1. initial number of ways to decode is set to 1
2. iterate through string to find additional decodes ways (+1 when found)
3. when find invalid 0 -> return 0

Analysis
1. time: O(n) where n = s.size()
2. space: O(1)
*/


class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;

        int ans = 1, n = s.size();
        vector<int> combination(n, 0);
        combination[0] = 1;

        for (int i = 1; i < n; ++i) {
            if (s[i] == '0') {
                if (s[i-1] != '1' && s[i-1] != '2') return 0;
            } else if (i+1 < n && s[i+1] == '0') {
                if (s[i] > '2') return 0;
            } else if (s[i-1] != '0') {
                if (10 * (s[i-1] - '0') + (s[i] - '0') <= 26) {
                    combination[i] += combination[i-1];
                    combination[i] += i == 1 ? 1 : combination[i-2];
                    continue;
                }
            }

            combination[i] = combination[i-1];
        }

        return combination[n-1];
    }
};

// 0: 1 | 1 2 3 1 2 3
// 1: 2 | 12 3 1 2 3
// 2: 3 | 1 23 1 2 3
// 3: 3 |
// 4: 6 | 1 2 3 12 3 / 12 3 12 3 / 1 23 12 3
// 5: 9 | 1 2 3 1 23 / 12 3 1 23 / 1 23 1 23