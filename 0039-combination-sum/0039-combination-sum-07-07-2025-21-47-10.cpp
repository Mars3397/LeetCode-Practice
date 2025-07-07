/*
Approach
1. use a backtracking approach to solve this problem

Analysis
1. time: O(n^2) where n = candidates.size()
2. space: O(target / minimum in candidates)
*/

class Solution {
private:
    vector<vector<int>> ans;
    int N, T;

    void backtrack(vector<int> &candidates, vector<int> &cur, int start, int curSum) {
        if (curSum == T) ans.emplace_back(cur);
        else if (curSum > T) return;

        for (int i = start; i < N; ++i) {
            cur.push_back(candidates[i]);
            backtrack(candidates, cur, i, curSum + candidates[i]);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        N = candidates.size(), T = target;
        vector<int> cur;
        backtrack(candidates, cur, 0, 0);

        return ans;
    }
};