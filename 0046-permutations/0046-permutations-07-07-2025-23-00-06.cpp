/*
Approach
1. use a backtracking approach to solve this problem
2. when inserting a new element, swap with all element before it

Analysis
1. time: O(n!) where n = nums.size()
2. space: O(n!) where n = nums.size()
*/

class Solution {
private: 
    vector<vector<int>> ans;
    int N;

    void backtrack(vector<int> &nums, vector<int> &path) {
        if (path.size() == N) {
            ans.push_back(path);
            return;
        }

        // push to the end of path
        path.push_back(nums[path.size()]);
        backtrack(nums, path);

        int n1 = path.size()-1;
        for (int i = 0; i < n1; ++i) {
            swap(path[i], path[n1]);
            backtrack(nums, path);
            swap(path[i], path[n1]);
        }

        path.pop_back();
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        N = nums.size();
        vector<int> path;
        backtrack(nums, path);
        
        return ans;
    }
};