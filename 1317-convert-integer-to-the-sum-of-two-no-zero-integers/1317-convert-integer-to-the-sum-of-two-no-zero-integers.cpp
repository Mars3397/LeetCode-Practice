/*
Approach
1. brute force to check all number between 1 - n

Analysis
1. time: O(nlogn)
2. space: O(1)
*/


class Solution {
private:
    bool isZeroInt(int num) {
        while (num > 0) {
            if (num % 10 == 0) return true;
            num /= 10;
        }

        return false;
    }

public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; ++i) {
            if (!isZeroInt(i) && !isZeroInt(n-i)) {
                return { i, n-i };
            }
        }

        return {};
    }
};
