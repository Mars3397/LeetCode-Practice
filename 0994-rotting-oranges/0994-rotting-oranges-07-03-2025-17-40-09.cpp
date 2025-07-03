/*
Approach
1. starting from the fresh oranges and perform BFS to find nearest rotten oragens
2. record the maxDistance to rotten oranges for each fresh orange

*/


class Solution {
private:
    int M, N;
    const vector<pair<int, int>> dirs = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

    int nearestRotten(vector<vector<int>> &grid, int i, int j) {
        queue<pair<pair<int, int>, int>> q; // ((i, j), level)
        unordered_set<int> visited;
        q.push({{i, j}, 0});
        visited.insert(i*100+j);

        while (!q.empty()) {
            auto [coord, level] = q.front(); q.pop();
            auto [x, y] = coord;

            for (auto [dx, dy] : dirs) {
                int ii = x + dx, jj = y + dy;
                if (0 <= ii && ii < M && 0 <= jj && jj < N) {
                    if (grid[ii][jj] == 1 && !visited.count(ii*100+jj)) { // fresh 
                        q.push({{ii, jj}, level+1});
                        visited.insert(ii*100+jj);
                    } else if (grid[ii][jj] == 2) { // found rotten
                        return level+1;
                    }
                }
            }
        }

        return -1;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        M = grid.size(), N = grid[0].size();
        int maxDis = 0;
        
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 1) {
                    int distance = nearestRotten(grid, i, j);
                    if (distance == -1) {
                        return -1;
                    }
                    maxDis = max(maxDis, distance);
                }
            }
        }

        return maxDis;
    }
};