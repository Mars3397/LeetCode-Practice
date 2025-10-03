/*
Approach
1. t * 2 will be the difference between num and maximum x
2. so the maximum x will be num + t * 2

Analysis
1. time: O(1)
2. space: O(1)
*/


class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + t * 2;
    }
};