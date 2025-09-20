/*
Approach 
1. sort both vector
2. check from the begin of vector to try to make child content

Analysis
1. time: O(nlogn)
2. space: O(1)
*/


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int count = 0;
        for (int i = 0, j = 0; i < g.size() && j < s.size(); ++i) {
            for ( ; j < s.size(); ++j) {
                if (s[j] >= g[i]) {
                    ++count; ++j;
                    break;
                }
            }
        }

        return count;
    }
};