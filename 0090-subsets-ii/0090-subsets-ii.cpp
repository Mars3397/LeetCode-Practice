/*
Approach
1. backtracking with condition
2. if nums[idx] == cur.back() -> skip

Analysis
1. time: O(2^n) where n = nums.size()
2. space: O(n) where n = nums.size()
*/

class Solution {
private:
    int N;
    vector<vector<int>> ans;

    void backtrack(const vector<int>& nums, int i, vector<int> &cur) {
        if (i == N) {
            ans.push_back(cur);
            return;
        }

        int next = i+1;
        while (next < N && nums[i] == nums[next]) {
            ++next;
        }

        backtrack(nums, next, cur);

        for (int j = i; j < next; ++j) {
            cur.push_back(nums[i]);
            backtrack(nums, next, cur);
        }

        for (int j = i; j < next; ++j) {
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        N = nums.size();

        // sort nums
        sort(nums.begin(), nums.end());

        vector<int> cur;
        backtrack(nums, 0, cur);

        return ans;
    }
};
