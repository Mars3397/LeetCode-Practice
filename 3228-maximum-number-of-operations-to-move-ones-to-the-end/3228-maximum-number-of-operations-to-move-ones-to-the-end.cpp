/*
Approach
1. move the frontest 1, then move the next one along with the 1's before it
2. in this way of moving we can create the maximum number of moves

Analysis
1. time: O(n)
2. space: 
*/


class Solution {
public:
    int maxOperations(string s) {
        int ans = 0, counterFor1 = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                if (i > 0 && s[i-1] == '0') {
                    ans += counterFor1;
                }
                ++counterFor1;
            } else if (i == s.size()-1 && s[i] == '0') {
                ans += counterFor1;
            }
        }

        return ans;
    }
};