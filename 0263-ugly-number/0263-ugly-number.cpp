/*
Approach
1. repeatly divide 2, 3, 5 until 0 or can't be devided
2. return the remaining is euqal to 1 or not

*/


class Solution {
public:
    bool isUgly(int n) {
        // divide 5
        while (n != 0 && n % 5 == 0) {
            n /= 5;
        }

        // divide 3
        while (n != 0 && n % 3 == 0) {
            n /= 3;
        }

        // divide 2
        while (n != 0 && n % 2 == 0) {
            n /= 2;
        }

        return n == 1;
    }
};