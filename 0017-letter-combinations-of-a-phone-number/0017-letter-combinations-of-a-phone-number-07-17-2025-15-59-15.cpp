/*
Approach
1. we can solve this with backtracking approach

Analysis
1. 
*/


class Solution {
    int N;
    vector<string> result;
    vector<vector<char>> mapping = {
        { 'a', 'b', 'c' }, { 'd', 'e', 'f' }, { 'g', 'h', 'i' },
        { 'j', 'k', 'l' }, { 'm', 'n', 'o' }, { 'p', 'q', 'r', 's' },
        { 't', 'u', 'v' }, { 'w', 'x', 'y', 'z' }
    };

    void backtrack(const string &digits, int idx, string &cur) {
        if (idx == N) {
            result.push_back(cur);
            return;
        }

        int mapIdx = digits[idx] - '2';
        for (char c : mapping[mapIdx]) {
            cur.push_back(c);
            backtrack(digits, idx+1, cur);
            cur.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        N = digits.size();
        if (N == 0) return result;

        string cur = "";
        backtrack(digits, 0, cur);

        return result;
    }
};