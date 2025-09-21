/*
Approach
1. equal to find left-most, right-most, up-most, down-most 1 cell
2. the distance of them will be height and width of target rectangle

Analysis
1. time: O(m*n) where m = grid.size(), n = grid[0].size()
2. space: O(1)
*/


class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        // initialization
        int m = grid.size(), n = grid[0].size();
        int left = n, right = 0, top = m, bottom = 0;

        // iterate through all the cells in grid
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    left = min(left, j);
                    right = max(right, j);
                    top = min(top, i);
                    bottom = max(bottom, i);
                }
            }
        }

        return (bottom - top + 1) * (right - left + 1);
    }
};