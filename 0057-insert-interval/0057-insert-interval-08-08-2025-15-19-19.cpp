/*
Approach
1. declare a new vector to store the result
2. keep push intervals to result vector while checking the insertion of newIntervals and merge overlapped intervals

Analysis
1. time: O(n) where n = intervals.size()
2. space: O(1) (don't count the output vector O(n))
*/

class Solution {
private:
    bool isOverlapped(vector<int> &i1, vector<int> &i2) {
        return i1[0] <= i2[1] && i2[0] <= i1[1];
    }

public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if (n == 0) return { newInterval };

        vector<vector<int>> ans;
        ans.reserve(n+1);
        bool isInserted = false;

        for (int i = 0; i < n; ++i) {
            if (!isInserted && newInterval[0] < intervals[i][0]) {
                if (!ans.empty() && isOverlapped(ans.back(), newInterval)) {
                    ans.back()[1] = max(ans.back()[1], newInterval[1]);
                    ans.back()[0] = min(ans.back()[0], newInterval[0]);
                } else {
                    ans.push_back(newInterval);
                }
                isInserted = true;
                --i;
            } else if (!ans.empty() && isOverlapped(ans.back(), intervals[i])) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }

        if (!isInserted) {
            if (isOverlapped(ans.back(), newInterval)) {
                ans.back()[1] = max(ans.back()[1], newInterval[1]);
                ans.back()[0] = min(ans.back()[0], newInterval[0]);
            } else {
                ans.push_back(newInterval);
            }
        }

        return ans;
    }
};