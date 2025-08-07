/*
Approach
1. 2 steps: swap diagonally, then swap horizontally

1 2 3    1 4 7    7 4 1
4 5 6 -> 2 5 8 -> 8 5 2
7 8 9    3 6 9    9 6 3

Analysis
1. time: O(n^2)
2. space: O(1)
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), half = n / 2;

        // swap along diagonal
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // swap horizontally
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < half; ++j) {
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
    }
};