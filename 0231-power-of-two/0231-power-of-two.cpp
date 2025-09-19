/*
Approach
1. check binary is consist of only one 1

Analysis
1. time: O(32) = O(1)
2. space: O(1)
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // negative number can't be the power of two
        if (n < 0) return false;

        int count = 0;
        while (n) {
            if (n & 1) ++count;
            n >>= 1; // right shift
        }

        return count == 1;
    }
};