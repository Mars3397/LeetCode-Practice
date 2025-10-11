/*
Approach
1. start with land cell and update all connected land to 0 (marked as explored), then +1 for island count
2. repeat until all cells are 0

Analysis
1. time: O(mn)
2. space: O(mn)
*/


class Solution {
private:
    int M, N;
    const vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void markLandCells(vector<vector<char>> &grid, int r, int c) {
        // mark as explored
        grid[r][c] = '0';

        // explore connected land
        for (auto [dr, dc] : dirs) {
            int nr = r + dr, nc = c + dc;
            if (0 <= nr && nr < M && 0 <= nc && nc < N && grid[nr][nc] == '1') {
                markLandCells(grid, nr, nc);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        // declare and init
        M = grid.size(), N = grid[0].size();
        int count = 0;

        // count island
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == '1') {
                    markLandCells(grid, i, j);
                    ++count;
                }
            }
        }

        return count;
    }
};