/*
Approach
1. return the person with smaller distance from person 3

Analysis
1. time: O(1)
2. space: O(1)
*/


class Solution {
public:
    int findClosest(int x, int y, int z) {
        int d1 = abs(z - x), d2 = abs(z - y);

        if (d1 == d2) return 0;

        return d1 < d2 ? 1 : 2;
    }
};