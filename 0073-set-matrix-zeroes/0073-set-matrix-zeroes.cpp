/*
Approach
1. first iterate the matrix to record which rows and cols need to be set to 0
2. then iterate to set matrix

Analysis
1. time: O(m*n) where m = matrix.size() and n = matrix[0].size()
2. space: O(m+n) where m = matrix.size() and n = matrix[0].size()
*/


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> zeroRows(m, false);
        vector<bool> zeroCols(n, false);

        // record zero rows and cols
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    zeroRows[i] = true;
                    zeroCols[j] = true;
                }
            }
        }

        // set cells to zero
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (zeroRows[i] || zeroCols[j]) {
                    matrix[i][j] = 0;
                }
            }
        }

        return;
    }
};