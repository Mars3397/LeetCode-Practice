/*
Approach
1. iterate through the matrix to find an island
2. explore the island while marking them as explored ('#')
3. add island count by one when finishing exploring an island

Analysis
1. time: O(m*n) where m = grid.size() and n = grid[0].size()
2. space: O(w) wehre w = the max area of island
*/


class Solution {
private:
    int M, N;
    const vector<pair<int, int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    void exploreIsland(vector<vector<char>> &grid, int i, int j) {
        grid[i][j] = '#';

        for (auto [x, y] : dirs) {
            int ii = i + x, jj = j + y;
            if (0 <= ii && ii < M && 0 <= jj && jj < N && grid[ii][jj] == '1') {
                exploreIsland(grid, ii, jj);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        M = grid.size(), N = grid[0].size();
        int islandCount = 0;

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == '1') {
                    exploreIsland(grid, i, j);
                    ++islandCount;
                }
            }
        }

        return islandCount;
    }
};