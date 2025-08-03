/*
Approach
1. solve using backtracking approach
2. when adding each number -> start from the next index

Analysis
1. time: O(2^n) where n = candidates.size()
2. space: 
*/


class Solution {
private:
    int N, T, curSum = 0;
    vector<int> cur;
    vector<vector<int>> ans;

    void backtracking(vector<int> &c, int start) {
        if (curSum > T) {
            return;
        } else if (curSum == T) {
            ans.push_back(cur);
            return;
        }

        // explore
        for (int i = start; i < N; ++i) {
            cur.push_back(c[i]);
            curSum += c[i];

            backtracking(c, i+1);

            cur.pop_back();
            curSum -= c[i];

            // skip same number
            while (i < N-1 && c[i] == c[i+1]) ++i;
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        N = candidates.size(), T = target;

        // sort the candidates to avoid duplicated combinations
        sort(candidates.begin(), candidates.end());

        // backtrack
        backtracking(candidates, 0);

        return ans;
    }
};