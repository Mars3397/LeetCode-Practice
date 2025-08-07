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

    void backtrack(vector<int>& nums, int idx) {
        if (idx == N) {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < N; ++i) {
            swap(nums[i], nums[idx]);
            backtrack(nums, idx + 1);
            swap(nums[i], nums[idx]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        N = nums.size();
        backtrack(nums, 0);
        return ans;
    }
};
