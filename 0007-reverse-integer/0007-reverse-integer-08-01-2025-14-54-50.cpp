/*
Approach
1. determine the sign of x and then start reversing
2. check the value when reversing, return 0 if exceed the boundary

Analysis
1. 
*/


class Solution {
public:
    int reverse(int x) {
        int ans = x % 10;
        x /= 10;

        while (x < 0) {
            int digit = x % 10;
            if (ans < (INT_MIN - digit) / 10) {
                return 0;
            }
            ans = ans * 10 + digit;
            x /= 10;
        }
        
        while (x > 0) {
            int digit = x % 10;
            if (ans > (INT_MAX - digit) / 10) {
                return 0;
            }
            ans = ans * 10 + digit;
            x /= 10;
        }

        return ans;
    }
};