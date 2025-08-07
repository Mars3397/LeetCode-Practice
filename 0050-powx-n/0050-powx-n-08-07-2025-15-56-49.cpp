/*
Approach
1. use binary exponantiation to solve this problem
2. take 2 ^ 10 as example
    -> 10 = 1010 in binary
    -> 2^10 = 2^8 * 2^2 = (1*2^8) * (0*2^4) * (1*2^2) * (0*2^1)

Analysis
1. time: O(logn)
2. space: O(1)
*/

class Solution {
public:
    double myPow(double x, int n) {
        // early return for n = 0
        if (n == 0) return 1;

        // replace n with long to prevent overflow when converting negstive to positive
        long ln = n;
        if (ln < 0) {
            ln *= -1;
            x = 1 / x;
        }

        double exp = 1;
        while (ln > 0) {
            if (ln & 1) exp *= x;

            x *= x;
            ln >>= 1;
        }

        return exp;
    }
};