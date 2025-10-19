class Solution {
public:
    bool isPowerOfFour(int n) {
        int cnt1 = 0, cnt0 = 0;
        while (n > 0) {
            if ((n & 1) == 1) ++cnt1;
            else ++cnt0;

            n >>= 1;
        }

        return cnt1 == 1 && (cnt0 & 1) == 0;
    }
};