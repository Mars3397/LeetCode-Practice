/*
Approach
1. first check the rightest bit
2. start checking alernating bits by right shift and bit-wise and

Analysis
1. time: O(32) = O(1)
2. space: O(1)
*/


class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool curBit = n & 1;

        while (n > 0) {
            if ((n & 1) != curBit) return false;

            curBit = !curBit;
            n >>= 1;
        }

        return true;
    }
};