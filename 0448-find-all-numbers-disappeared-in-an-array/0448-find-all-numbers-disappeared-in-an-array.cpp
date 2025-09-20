/*
Approach
1. mark the seen number by making the number in its index negative
2. for example, we encounter 4 -> mark element in index = 4 negative
3. after a loop, the positive element indicates that its index is a disappeared number

Analysis
1. time: O(n)
2. space: O(1)
*/


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int num : nums) {
            int idx = abs(num)-1;

            // mark as negative
            if (nums[idx] > 0) nums[idx] *= -1;
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) result.push_back(i+1);
        }

        return result;
    }
};