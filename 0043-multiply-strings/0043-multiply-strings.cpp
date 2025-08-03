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
        int m = num1.size(), n = num2.size(), mn = m * n + 1;
        vector<int> nums(mn, 0);

        // calculate all intermidiate numbers
        for (int i = m - 1; i >= 0; --i) {
            int d1 = num1[i] - '0';

            for (int j = n - 1; j >= 0; --j) {
                int d2 = num2[j] - '0';

                int idx = (mn-1) - (m-1-i) - (n-1-j);
                nums[idx] += d1 * d2;

                // handle carry
                nums[idx-1] += nums[idx] / 10;
                nums[idx] %= 10;
            }
        }

        // skip leading zero
        int idx = 0;
        while (idx < mn && nums[idx] == 0) ++idx;

        // form the result string (reversely)
        string ans = "";
        for (int i = idx; i < mn; ++i) {
            ans += to_string(nums[i]);
        }

        return ans == "" ? "0" : ans;
    }
};
