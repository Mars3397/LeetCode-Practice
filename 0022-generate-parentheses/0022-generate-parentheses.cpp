/*
Approach
1. use backtracking approach to solve this problem
2. at the start we have n left parentheses and n right parentheses
3. appand a parenthese to current string while make sure right didn't exceed left
4. push the string to result vector when use all the parentheses

Analysis
1. time: O(n^2)
2. space: O(n)
*/

class Solution {
private:
    vector<string> ans;

    void backtracking(int l, int r, string &cur) {
        if (l == 0 && r == 0) {
            ans.push_back(cur);
            return;
        }

        if (l > 0) {
            cur.push_back('(');
            backtracking(l-1, r, cur);
            cur.pop_back();
        }
        if (r > l) {
            cur.push_back(')');
            backtracking(l, r-1, cur);
            cur.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        string cur = "";
        backtracking(n, n, cur);

        return ans;
    }
};
