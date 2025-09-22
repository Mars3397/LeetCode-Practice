/*
Approach
1. first sort the nums to let us can skip duplicate numbers
2. use a 2 pointer approach to find triplets

Analysis
1. time: O(nlogn) + O(n^2) = O(n^2)
2. space: O(n)
*/



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort number in nums
        sort(nums.begin(), nums.end());

        // declaration
        vector<vector<int>> result;
        int n = nums.size();

        // start finding
        for (int i = 0; i < n; ++i) {
            int target = -nums[i];

            int l = i+1, r = n-1;
            while (l < r) {
                int sum = nums[l] + nums[r];

                if (sum == target) {
                    result.push_back({ nums[i], nums[l], nums[r] });

                    // skip duplicate
                    while (l < r && nums[l] == nums[l+1]) ++l;
                    while (l < r && nums[r] == nums[r-1]) --r;
                    ++l; --r;
                } else if (sum < target) {
                    ++l;
                } else {
                    --r;
                }
            }

            // skip duplicate 
            while (i < n-1 && nums[i] == nums[i+1]) ++i;
        }

        return result;
    }
};