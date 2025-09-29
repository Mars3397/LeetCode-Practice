/*
Test cases: 

1 0 0 
0 1 0 => 3
0 0 1

1 1 0
0 1 1 => 2
1 0 0

1 1
1 1 => 1

0 0 
0 0 => 0

Approach
1. BFS/DFS for each cell with '1' to explore the whole island
2. mark explored land as '#' to avoid duplicate exploration
3. plus one for island count when finish BFS/DFS exploration

Analysis
1. time: O(m * n)
2. space: O(m * n)
*/



class Solution {
private:
    vector<pair<int, int>> dirs = { {0, -1}, {0, 1}, {1, 0}, {-1,0} };
    int M, N;

    void BFSExploration(vector<vector<char>> &grid, int &islandCount, int i, int j) {
        queue<pair<int, int>> q; // (i, j)
        q.push({ i, j }); // starting point
        
        // mark as explored
        grid[i][j] = '#';

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();

            // explore neighbors with land
            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (0 <= nr && nr < M && 0 <= nc && nc < N && grid[nr][nc] == '1') {
                    q.push({ nr, nc });
                    
                    // mark as explored
                    grid[nr][nc] = '#';
                }
            }
        }

        ++islandCount;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        // initialzation
        int islandCount = 0;
        M = grid.size(), N = grid[0].size();

        // exploration (BFS)
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == '1') {
                    BFSExploration(grid, islandCount, i, j);
                }
            }
        }

        return islandCount;
    }
};