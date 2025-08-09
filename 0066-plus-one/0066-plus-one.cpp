/*
Approach
1. +1 from the end of array and handle carry to the start of array
2. insert 1 to the begin of array if has carry

Analysis
1. time: O(n) where n = digits.size()
2. space: O(1)
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        for (int i = digits.size() - 1; i >= 0; --i) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
            if (!carry) break;
        }

        if (carry) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};