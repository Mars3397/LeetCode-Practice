/*
Approach
1. for each cell, try to match the word using backtracking with status track
2. optimize: calculate tehe frequency of the board to make sure might exist word

Analysis
1. time: O(m*n*l) where m = borad.size(), n = board[0].size(), l = word.size()
2. space: O(l) where l = word.size()
*/


class Solution {
private:
    int M, N, L;
    string W;
    vector<vector<char>> B;
    const vector<pair<int, int>> dirs = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

    bool checkFreq() {
        unordered_map<char, int> freqB, freqW;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                ++freqB[B[i][j]];
            }
        }

        for (char c : W) {
            ++freqW[c];
        }

        for (auto &[c, t] : freqW) {
            if (freqB[c] < t) return false;
        }

        return true;
    }

    bool explore(int i, int j, int start) {
        if (start == L) return true;

        if (B[i][j] != W[start]) return false;
        char temp = B[i][j];
        B[i][j] = '#'; // mark as visited

        for (auto &[di, dj] : dirs) {
            int x = i + di, y = j + dj;
            if (0 <= x && x < M && 0 <= y && y < N && B[x][y] != '#') {
                if (explore(x, y, start+1)) {
                    return true;
                }
            }
        }

        B[i][j] = temp;

        return start == L - 1 && B[i][j] == W[start];
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        M = board.size(), N = board[0].size(); L = word.size(); 
        B = board, W = word;

        if (!checkFreq()) return false;

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (explore(i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};