/*
Approach
1. sort nums
2. use a 2 pointers approach to find triplets

Analysis
1. time: O(nlogn) + O(n^2) = O(n^2)
2. space: O(1)
*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            // skip duplicates
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int l = i+1, r = n-1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    result.push_back({ nums[i], nums[l], nums[r] });
                    // skip duplicates
                    while (l < n-1 && nums[l] == nums[l+1]) {
                        ++l;
                    }

                    while (r > 1 && nums[r] == nums[r-1]) {
                        --r;
                    }

                    ++l; --r;
                } else if (sum > 0) {
                    --r;
                } else {
                    ++l;
                }
            }
        }

        return result;
    }
};