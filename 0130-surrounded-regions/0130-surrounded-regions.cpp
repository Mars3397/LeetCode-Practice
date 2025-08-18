/*
Approach
1. declare a boolean board to record not surrounded cell
2. use BFS to push all edge cell with 'O' to queue
3. set all adjacent 'O' cell to not surround until no cell in queue
4. iterate through board to set surrounded cell

Analysis
1. time: O(mn)
2. space: O(mn)
*/


class Solution {
private:
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> surrounded(m, vector<bool>(n, true));
        queue<pair<int, int>> q;

        // push all 'O' cells on the edge to queue
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') q.push({i, 0});
            if (board[i][n-1] == 'O') q.push({i, n-1});
        }

        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') q.push({0, j});
            if (board[m-1][j] == 'O') q.push({m-1, j});
        }

        // BFS to push not surrounded cells
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            surrounded[i][j] = false;
            for (auto [di, dj] : dirs) {
                int ni = i+di, nj = j+dj;
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if (board[ni][nj] == 'O' && surrounded[ni][nj]) {
                    q.push({ni, nj});
                }
            }
        }

        // update cells according to surrounded
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && surrounded[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};