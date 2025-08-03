/*
Approach
1. use a vector to store all the intermidiate numbers 
2. deal with the carry and form the result string

Analysis
1. time: O()
2. space:
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size(), mn = m * n;
        vector<int> nums(mn, 0);

        // calculate all intermidiate numbers
        for (int i = 0; i < m; ++i) {
            int d1 = num1[i] - '0';

            for (int j = 0; j < n; ++j) {
                int d2 = num2[j] - '0';

                nums[i+j] += d1 * d2;
            }
        }

        // skip leading zero
        int idx = mn - 1, carry = 0;
        while (idx >= 0 && nums[idx] == 0) --idx;

        // deal with carries and form the result string (reversely)
        string ans = idx < 0 ? "0" : "";
        for (int i = idx; i >= 0; --i) {
            nums[i] += carry;
            carry = nums[i] / 10;
            ans = to_string(nums[i] % 10) + ans;
        }

        // handle carry for the first digit
        if (carry > 0) ans = to_string(carry) + ans;

        return ans;
    }
};
