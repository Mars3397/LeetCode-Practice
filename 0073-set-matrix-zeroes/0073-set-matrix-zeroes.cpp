/*
Approach
1. first iterate the matrix to record which rows and cols need to be set to 0
2. then iterate to set matrix

Optimization
1. reduce the space complexity to O(1)
2. -> record zero rows and cols using first row and col
3. require other 2 boolean to record wether first row and col is zero

Analysis
1. time: O(m*n) where m = matrix.size() and n = matrix[0].size()
2. space: O(m+n) where m = matrix.size() and n = matrix[0].size()
3. space: O(1) after optimization
*/


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool zeroFirstRow = false, zeroFirstCol = false;

        for (int i = 0; i < n; ++i) {
            if (matrix[0][i] == 0) {
                zeroFirstRow = true;
                break;
            }
        }

        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                zeroFirstCol = true;
                break;
            }
        }

        // record zero rows and cols
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // set cells to zero
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (zeroFirstRow) {
            for (int i = 0; i < n; ++i) {
                matrix[0][i] = 0;
            }
        }

        if (zeroFirstCol) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }

        return;
    }
};