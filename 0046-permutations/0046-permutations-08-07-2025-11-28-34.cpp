/*
Approach
1. perform a swap of 2 elements will form a new permutation
2. perform swaps until reach the end of vector

Analysis
1. time: O(n^3) where n = nums.size()
2. space: O(n) where n = nums.size()
*/

class Solution {
private:
    vector<vector<int>> ans;
    int N;

    void explorer(vector<int>& nums, int idx1) {
        for (int i = idx1; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                swap(nums[i], nums[j]);
                ans.push_back(nums);
                explorer(nums, i+1);
                swap(nums[i], nums[j]);
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        N = nums.size();
        ans.push_back(nums);
        explorer(nums, 0);
        return ans;
    }
};