/*
Approach
1. only the o cell connected to the edge of the matrix can remain 0 (mark them to '.')
2. flip all non '.' O cell to X

Analysis
1. time: 
2. space:
*/

class Solution {
private: 
    int M, N;
    const vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void markCells(vector<vector<char>>& board, int r, int c) {
        // mark as unsurrounded
        board[r][c] = '.';

        for (auto [dr, dc] : dirs) {
            int nr = r + dr, nc = c + dc;
            if (0 <= nr && nr < M && 0 <= nc && nc < N && board[nr][nc] == 'O') {
                markCells(board, nr, nc);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        M = board.size(), N = board[0].size();

        // mark unsurrounded region
        // first and last columns
        for (int i = 0; i < M; ++i) {
            if (board[i][0] == 'O') markCells(board, i, 0);
            if (board[i][N-1] == 'O') markCells(board, i, N-1);
        }
        // first and last rows
        for (int j = 0; j < N; ++j) {
            if (board[0][j] == 'O') markCells(board, 0, j);
            if (board[M-1][j] == 'O') markCells(board, M-1, j);
        }

        // flip surrounded region
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '.') board[i][j] = 'O';
            }
        }

        return;
    }
};