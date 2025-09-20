/*
Approach
1. solve using sliding window
2. single pass while recording the maximum average

Analysis
1. time: O(n) where n = nums.size()
2. space: O(1)
*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int cur = 0, idx = 0;

        // sum to first window
        while (idx < k) {
            cur += nums[idx++];
        }

        // slide to the end to record max sum
        int maximum = cur, n = nums.size();
        for ( ; idx < n; ++idx) {
            cur += nums[idx];
            cur -= nums[idx - k];

            maximum = max(maximum, cur);
        }

        return (double)maximum / (double)k;
    }
};