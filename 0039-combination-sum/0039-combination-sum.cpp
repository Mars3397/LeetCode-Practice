/*
Approach
1. solve by backtracking
2. recursively to add number to current number until exceed the target
3. try next number after exceed

Analysis
1. time: 
2. space: 
*/


class Solution {
private: 
    int N, T;
    vector<vector<int>> ans;

    void backtracking(const vector<int> &cands, int start, vector<int> &cur, int &curSum) {
        if (curSum > T) {
            return;
        } else if (curSum == T) {
            ans.push_back(cur);
            return;
        }

        for (int i = start; i < N; ++i) {
            cur.push_back(cands[i]);
            curSum += cands[i];
            backtracking(cands, i, cur, curSum);
            cur.pop_back();
            curSum -= cands[i];
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        N = candidates.size(), T = target;

        vector<int> cur; int curSum = 0;
        backtracking(candidates, 0, cur, curSum);

        return ans;
    }
};