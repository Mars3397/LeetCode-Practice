class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        res.reserve(m * n); // 預留空間避免重分配

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        while (top <= bottom && left <= right) {
            // 1) 往右：固定 top 行，從 left 到 right
            for (int c = left; c <= right; ++c)
                res.push_back(matrix[top][c]);
            ++top; // 已走訪完最上面一行

            // 2) 往下：固定 right 列，從 top 到 bottom
            for (int r = top; r <= bottom; ++r)
                res.push_back(matrix[r][right]);
            --right; // 已走訪完最右邊一列

            if (top <= bottom) {
                // 3) 往左：固定 bottom 行，從 right 到 left
                for (int c = right; c >= left; --c)
                    res.push_back(matrix[bottom][c]);
                --bottom; // 已走訪完最下面一行
            }

            if (left <= right) {
                // 4) 往上：固定 left 列，從 bottom 到 top
                for (int r = bottom; r >= top; --r)
                    res.push_back(matrix[r][left]);
                ++left; // 已走訪完最左邊一列
            }
        }
        return res;
    }
};

// 1  2  3  4
// 5  6  7  8
// 9  10 11 12
// 13 14 15 16
// 17 18 19 20
// 21 22 23 24