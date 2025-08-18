/*
Approach
1. xor all the num in nums, every pair of number will cancel out each other

*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (int num : nums) {
            ans ^= num;
        }

        return ans;
    }
};