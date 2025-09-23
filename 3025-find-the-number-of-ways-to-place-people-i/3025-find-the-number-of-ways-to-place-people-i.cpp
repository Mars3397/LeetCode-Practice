class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // grid[x][y] = 1 if a point exists at (x,y)
        int grid[52][52] = {0};
        for (auto &p : points) grid[p[0]][p[1]] = 1;

        // 1-based prefix sum psum[x][y] over x,y in [1..51]
        int psum[52][52] = {0};
        for (int x = 1; x <= 51; ++x) {
            for (int y = 1; y <= 51; ++y) {
                psum[x][y] = grid[x-1][y-1]
                           + psum[x-1][y]
                           + psum[x][y-1]
                           - psum[x-1][y-1];
            }
        }

        auto rect = [&](int x1, int y1, int x2, int y2) {
            // closed rectangle [x1..x2] × [y1..y2], with 0-based coords
            ++x1; ++y1; ++x2; ++y2; // to 1-based
            return psum[x2][y2] - psum[x1-1][y2] - psum[x2][y1-1] + psum[x1-1][y1-1];
        };

        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int ax = points[i][0], ay = points[i][1];
            for (int j = 0; j < n; ++j) if (i != j) {
                int bx = points[j][0], by = points[j][1];
                // A is on the upper-left side of B (allow same row/col)
                if (ax <= bx && ay >= by) {
                    // rectangle (closed) must contain exactly A and B
                    if (rect(ax, by, bx, ay) == 2) ++ans;
                }
            }
        }
        return ans;
    }
};
