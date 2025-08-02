/*
Approach
1. use a backtracking approach to solve this problem
2. push all possible combination to a result vector

Analysis
1. time: O(n^4) where n = length of digits
2. space: O(n) where n = length of digits
*/


class Solution {
private:
    vector<string> ans;
    int N;

    // use to map number to letters
    vector<string> mapping = {
        "", "", "abc", "def", 
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    void backtracking(const string &digits, int idx, string &cur) {
        if (idx == N) {
            ans.push_back(cur);
            return;
        }

        int mapIdx = digits[idx] - '0';
        for (char c : mapping[mapIdx]) {
            cur.push_back(c);
            backtracking(digits, idx+1, cur);
            cur.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        N = digits.size();

        // handle length of digits == 0
        if (N == 0) return {};

        // perform the backtracking approach
        string cur = "";
        backtracking(digits, 0, cur);

        return ans;
    }
};