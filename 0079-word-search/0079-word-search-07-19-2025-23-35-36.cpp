/*
Approach
1. perform a DFS search in each cell to match the target

Analysis
1. time: O(m * n * l) where m = board.size(), n = board[0].size() and l = word.size()
2. space: O(l) where l = word.size()
*/


class Solution {
private:
    vector<pair<int, int>> direc = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };
    string WORD;
    int M, N;

    bool DFS(vector<vector<char>>& board, int idx, int x, int y) {
        // match char in current cell with current string index
        if (WORD[idx] != board[x][y]) return false;

        // return true if reach the end
        if (idx+1 == WORD.size()) return true;

        // mark as seen
        char origin = board[x][y];
        board[x][y] = '#';
        
        // check the adjcent unseen cells
        for (auto [dx, dy] : direc) {
            int newX = x + dx, newY = y + dy;
            if (0 <= newX && newX < M && 0 <= newY && newY < N && board[newX][newY] != '#') {
                if (DFS(board, idx+1, newX, newY)) return true;
            }
        }

        // recover
        board[x][y] = origin;

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        // init
        WORD = word, M = board.size(), N = board[0].size();
        
        // DFS for each cell
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (DFS(board, 0, i, j)) return true;
            }
        }

        return false;
    }
};