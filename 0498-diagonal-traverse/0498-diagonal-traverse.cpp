/*



*/


class Solution {
private: 
    const pair<int, int> toTopRight = { -1, 1 };
    const pair<int, int> toBottomLeft = { 1, -1 };

public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), mn = m * n;
        vector<int> result;
        result.reserve(mn);

        int r = 0, c = 0;
        bool isTopRight = true;

        while (result.size() < mn) {
            result.push_back(mat[r][c]);

            if (isTopRight) {
                int nr = r + toTopRight.first, nc = c + toTopRight.second;
                if (0 <= nr && nr < m && 0 <= nc && nc < n) {
                    r = nr; c = nc;
                } else {
                    nc = c + 1;
                    if (nc < n) {
                        c = nc;
                    } else {
                        ++r;
                    }

                    isTopRight = !isTopRight;
                }
            } else {
                int nr = r + toBottomLeft.first, nc = c + toBottomLeft.second;
                if (0 <= nr && nr < m && 0 <= nc && nc < n) {
                    r = nr; c = nc;
                } else {
                    nr = r + 1;
                    if (nr < m) {
                        r = nr;
                    } else {
                        ++c;
                    }

                    isTopRight = !isTopRight;
                }
            }
        }

        return result;
    }
};