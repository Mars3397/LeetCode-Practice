/*
Approach
1. sort the intervals base on their start
2. declare a vector<vector<int> to store merged intervals
3. compare the last interval and merge overlapping intervals

Analysis
1. time: O(nlogn) where n = intervals.size()
2. space: O(n) where n = intervals.size()
*/


class Solution {
private: 
    bool isOverlap(vector<int> &a, vector<int> &b) {
        return a[1] >= b[0] && a[0] <= b[1];
    }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());
        for (auto &interval : intervals) {
            if (ans.empty() || !isOverlap(ans.back(), interval)) {
                ans.push_back(interval);
            } else {
                ans.back()[0] = min(ans.back()[0], interval[0]);
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }

        return ans;
    }
};