/*
Approach
1. sort the intervals based on their start
2. iterate through intervals to merge overlapping intervals

Analysis
1. time: O(nlogn) where n = intervals.size()
2. space: O(1)
*/


class Solution {
private:
    bool isOverlap(int s1, int e1, int s2, int e2) {
        return s1 <= e2 && s2 <= e1;
    }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for (int i = 1; i < n; ++i) {
            if (isOverlap(ans.back()[0], ans.back()[1], intervals[i][0], intervals[i][1])) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};