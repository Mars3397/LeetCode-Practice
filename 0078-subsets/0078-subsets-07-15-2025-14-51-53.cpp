/*
Approach
1. use a backtrackign approach to solve this problem
2. in every index we we divide 2 ways: select or not select for nums[i]

Anaysis
1. time: O(2 ^ n) where n = nums.size()
2. space: O(n) where n = nums.size()
*/

class Solution {
private:
    vector<vector<int>> res;
    int N;

    void backtrack(vector<int> &nums, vector<int> &cur, int idx) {
        if (idx >= N) {
            res.push_back(cur);
            return;
        }

        // not select i
        backtrack(nums, cur, idx+1);

        // select i
        cur.push_back(nums[idx]);
        backtrack(nums, cur, idx+1);
        cur.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        N = nums.size();
        vector<int> cur;

        backtrack(nums, cur, 0);

        return res;
    }
};