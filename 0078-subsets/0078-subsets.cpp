/*
Approach
1. use backtracking approach to solve
2. for each element: push or not push

Analysis
1. time: O(2^n) where n = nums.size()
2. space: O
*/

class Solution {
private:
    vector<vector<int>> ans;
    int N;

    void backtrack(vector<int> &nums, int idx, vector<int> &cur) {
        if (idx == N) {
            ans.push_back(cur);
            return;
        }

        backtrack(nums, idx+1, cur);
        cur.push_back(nums[idx]);
        backtrack(nums, idx+1, cur);
        cur.pop_back(); // recover since we use cur repeatly
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        N = nums.size();
        vector<int> cur;
        cur.reserve(N);
        ans.reserve(pow(2, N));

        backtrack(nums, 0, cur);

        return ans;
    }
};