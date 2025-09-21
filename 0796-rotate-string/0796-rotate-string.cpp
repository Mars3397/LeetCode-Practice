/*
Approach
1. start from each index of string s, try to match goal
2. restart from the start of s when reaching string end
3. len(s) must euqal to len(goal) if it is shifted

Analysis
1. time: O(mn) where m = s.size(), n = goal.size()
2. space: O(1)
*/


class Solution {
public:
    bool rotateString(string s, string goal) {
        int ns = s.size(), ng = goal.size();
        if (ns != ng) return false;

        // match for each index in s
        for (int i = 0; i < ns; ++i) {
            bool matched = true;
            for (int j = 0; j < ng; ++j) {
                if (s[(i+j) % ns] != goal[j]) {
                    matched = false;
                    break;
                }
            }

            if (matched) return true;
        }

        return false;
    }
};