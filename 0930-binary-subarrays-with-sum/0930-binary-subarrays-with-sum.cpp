/*
Approach
1. # subarrays' sum = target => # subarrays' sum <= target - # subarrays' sum <= target - 1
2. by converting the question into the approach in the above, we can use a sliding window approach to solve

Analysis
1. time: 
2. space: 

*/


class Solution {
private: 
    int N;

    int atMost(vector<int> &nums, int most) {
        if (most < 0) return 0;
        
        int cnt = 0, sum = 0;

        for (int l = 0, r = 0; r < N; ++r) {
            sum += nums[r];

            while (sum > most) {
                sum -= nums[l++];
            }

            cnt += r - l + 1;
        }

        return cnt;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        N = nums.size();

        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};