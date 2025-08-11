/*
Approach
1. 2 binary search: one for row and one for col

Analysis
1. time: log(m) + log(n) where m = matrix.size() and n = matrix[0].size()
2. space: O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        // search for row (lower bound search)
        int rl = 0, rr = m;
        while (rl < rr) {
            int mid = rl + (rr - rl) / 2;
            if (matrix[mid][0] < target) rl = mid + 1;
            else rr = mid;
        }

        // return true if match row start
        if (rl < m && matrix[rl][0] == target) return true;

        // minus one since previous search is lower bound search
        if (--rl < 0) return false;

        // search in the row
        int cl = 0, cr = n-1;
        while (cl <= cr) {
            int mid = cl + (cr - cl) / 2;
            if (matrix[rl][mid] == target) return true;
            else if (matrix[rl][mid] < target) cl = mid + 1;
            else cr = mid - 1;
        }

        return false;
    }
};