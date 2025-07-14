/*
Approach
1. declare a long to store the converted integer
2. read the char from the start of the string
3. mulitple 10 to the stored integer every time before new char append

*/


class Solution {
private: 
    bool isNumber(char c) {
        return '0' <= c && c <= '9';
    }

public:
    int myAtoi(string s) {
        long res = 0;
        int idx = 0, n = s.size();

        // remove all leading space
        while (idx < n && s[idx] == ' ') ++idx;

        // determine the sign of integer
        bool positive = true;
        if (s[idx] == '-') {
            positive = false;
            ++idx;
        } else if (s[idx] == '+') {
            ++idx;
        }

        // convert the number
        while (isNumber(s[idx])) {
            res *= 10;
            res += s[idx] - '0';
            ++idx;

            // early break
            if (res > INT_MAX) {
                return positive ? INT_MAX : INT_MIN;
            }
        }

        // add the sign
        if (!positive) res *= -1;

        // rounding
        if (res > INT_MAX) return INT_MAX;
        if (res < INT_MIN) return INT_MIN;

        return int(res);
    }
};