/*
Approach
1. declare a frequency map for each row, col, and squares
2. iterate thorugh all filled cells
3. if has duplicate -> return false

Analysis
1. time: O(9*9)
2. space: O(9*9*3)
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool> (9, false));
        vector<vector<bool>> col(9, vector<bool> (9, false));
        vector<vector<bool>> square(9, vector<bool> (9, false));

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                // skip not filled cells
                if (board[i][j] == '.') continue;

                int idx = board[i][j] - '1';

                // check row
                if (row[i][idx]) return false;
                row[i][idx] = true;

                // check col
                if (col[j][idx]) return false;
                col[j][idx] = true;

                // check square
                int squ = (i / 3) * 3 + (j / 3);
                if (square[squ][idx]) return false;
                square[squ][idx] = true;
            }
        }

        return true;
    }
};