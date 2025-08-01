/*
Approach
1. first count the number of fresh orange, and push rotten orange to a queue
2. for each round: pop out n = queue.size() orange and update the adjacent fresh ones to rotten
3. push the new rotten orange to queue and minus one from fresh count
4. repeat until no orange in queue or fresh count = 0

Analysis
1. 
*/

class Solution {
private:
    const vector<pair<int, int>> dirs = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int fresh = 0, minute = 0;
        queue<pair<int, int>> q;

        // count fresh and push rotten
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) ++fresh;
                else if (grid[i][j] == 2) q.push({i, j});
            }
        }

        // start rotting
        while (!q.empty() && fresh > 0) {
            ++minute;
            int cur = q.size();

            // pop q.size() oranges (all belong to this round)
            for (int i = 0; i < cur; ++i) {
                auto [x, y] = q.front(); q.pop();

                // check adjacent oranges
                for (auto [dx, dy] : dirs) {
                    int xx = x + dx, yy = y + dy;

                    // update fresh count and push orange when encountering fresh oranges
                    if (0 <= xx && xx < m && 0 <= yy && yy < n && grid[xx][yy] == 1) {
                        --fresh;
                        grid[xx][yy] = 2;
                        q.push({xx, yy});
                    }
                }
            }
        }

        // if fresh > 0 (q.size() == 0) -> impossible to reach all fresh oranges from rotten ones
        return fresh == 0 ? minute : -1;
    }
};