class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = static_cast<int>(digits.size());
        ++digits[n-1];

        bool carry = false;
        for (int i = n-1; i >= 0; --i) {
            carry = (digits[i] / 10) > 0;
            digits[i] %= 10;

            if (!carry) return digits;
        }

        if (carry) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};