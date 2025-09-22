/*
Approach
1. if negative number -> return false
2. keep move the right-most digits to another number until the new number >= original one
3. check they are equal or not

Analysis
1. time: O(logx)
2. space: O(1)
*/


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        long long y = 0, xx = x;

        while (x > 0) {
            y *= 10;
            y += x % 10;
            x /= 10;
        }

        return xx == y;
    }
};