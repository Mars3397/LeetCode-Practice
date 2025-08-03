/*
Approach
1. within the reachable interval, choose the one that can jump the farest
2. repeat until reach the end

Analysis
1. time: O(n) where n = nums.size()
2. space: O(1)
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), idx = 0, step = 0;
        if (n == 1) return 0;
        
        while (step < n) {
            if (idx + nums[idx] >= n-1) return step + 1;

            int maxReach = 0, end = min(n-1, nums[idx]) + idx;
            for (int i = idx+1; i <= end; ++i) {
                if (i + nums[i] >= maxReach) {
                    maxReach = i + nums[i];
                    idx = i;
                }
            }

            ++step;
        }

        return 0;
    }
};