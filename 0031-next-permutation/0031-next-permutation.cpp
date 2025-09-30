/*
Approach
1. find first pairs [i, j] where j > i from the end of nums
2. if found swap them, if not -> sort the nums

Analysis
1. time: O(n^2) where n = nums.size()
2. space: O(1)
*/


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find pairs from the end of nums
        int n = nums.size(), minNext = INT_MAX, minNextIdx = -1;

        for (int i = n-2; i >= 0; --i) {
            for (int j = i+1; j < n; ++j) {
                if (nums[j] > nums[i] && nums[j] < minNext) {
                    minNext = nums[j];
                    minNextIdx = j;
                }
            }

            if (minNextIdx != -1) {
                swap(nums[i], nums[minNextIdx]);
                sort(nums.begin()+i+1, nums.end());
                return;
            }
        }

        sort(nums.begin(), nums.end());

        return;
    }
};