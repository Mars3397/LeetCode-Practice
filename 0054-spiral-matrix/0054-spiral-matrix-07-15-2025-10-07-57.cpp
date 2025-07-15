class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        vector<int> res;
        res.reserve(matrix.size() * matrix[0].size());
        
        while (top <= bottom && left <= right) {
            // left to right on top
            for (int i = left; i <= right; ++i) {
                res.push_back(matrix[top][i]);
            }
            ++top;

            // top to bottom on right
            for (int i = top; i <= bottom; ++i) {
                res.push_back(matrix[i][right]);
            }
            --right;

            // right to left on bottom
            if (top <= bottom) { // to avoid duplicate push with left to right
                for (int i = right; i >= left; --i) {
                    res.push_back(matrix[bottom][i]);
                }
                --bottom;
            }

            // bottom to top on left
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    res.push_back(matrix[i][left]);
                }
                ++left;
            }
        }

        return res;
    }
};