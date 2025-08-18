/*
Approach
1. declare answer vector and push all char as vector to answer
2. start from each index to expand palindrome -> if can, push to answer vector

Analysis
1. time: O(n^2) where n = s.size()
2. space: O(1) (don't count return vector)
*/

class Solution {
private:
    int N;

    // validate string a + b is palindrome or not
    bool isPalindrome(string &a, string &b) {
        int na = a.size(), nb = b.size();
        int l = 0, r = na + nb - 1;

        while (l < r) {
            if ((l < na ? a[l] : b[l-na]) != (r < na ? a[r] : b[r-na])) return false;
            ++l; --r;
        }

        return true;
    }

    void expand(int le, int ls, int rs, vector<vector<string>> &ans, string &s, int idx) {
        int n = ans[idx].size();

        // cout << "check: " << le << " " << ls << " " << rs << " " << n << endl;
        while (le < ls && rs < n && isPalindrome(ans[idx][ls], ans[idx][rs])) {
            // push the current palindrome parition to answer vector
            ans.push_back({}); int i = ans.size()-1;
            for (int j = 0; j < n; ++j) {
                if (j == ls) {
                    string str = "";
                    while (j <= rs) str += ans[idx][j++];
                    ans[i].push_back(str); --j;
                } else {
                    ans[i].push_back(ans[idx][j]);
                }
            }
            // cout << "based on: " << idx << " -> " << ls << ", " << rs << endl;

            // keep expand based on current palindrome partition
            int size = ans[i].size();
            for (int k = ls + 2; k < size; ++k) {
                expand(ls, k-1, k, ans, s, i);
                if (k != size-1) expand(ls, k-1, k+1, ans, s, i);
            }

            // expand
            --ls; ++rs;
        }
    }

public:
    vector<vector<string>> partition(string s) {
        N = s.size();
        vector<vector<string>> ans;

        // single characters
        ans.push_back({});
        for (int i = 0; i < N; ++i) {
            ans[0].push_back(string(1, s[i]));
        }

        for (int i = 1; i < N; ++i) {
            expand(-1, i-1, i, ans, s, 0);
            if (i != N-1) expand(-1, i-1, i+1, ans, s, 0);
        }

        return ans;
    }
};