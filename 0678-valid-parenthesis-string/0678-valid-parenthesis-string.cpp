/*
Approach
1. maintain the range fo minimal and maximal number of unclosed left
2. 

Analysis
1. time: O(n)
2. space: O(1)
*/

class Solution {
public:
    bool checkValidString(string s) {
        // minLeft = number of unclosed left if * is all treated as empty or right
        // maxLaft = number of unclosed left if * is all treated as empty or left
        int minLeft = 0, maxLeft = 0;

        for (char c : s) {
            if (c =='(') {
                ++minLeft; ++maxLeft;
            } else if (c == ')') {
                --minLeft; --maxLeft;
            } else {
                --minLeft; ++maxLeft;
            }

            // number of right exceed left + all *
            if (maxLeft < 0) return false;

            // maintain at 0
            minLeft = max(minLeft, 0);
        }

        return minLeft == 0;
    }
};