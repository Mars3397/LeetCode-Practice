class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), mn = m * n;
        vector<int> ans;
        ans.reserve(mn);
        
        int rs = 0, re = m - 1, cs = 0, ce = n - 1;
        while (ans.size() < mn) {
            // left -> right
            for (int i = cs; i <= ce; ++i) {
                ans.push_back(matrix[rs][i]);
            }
            ++rs;

            // top -> down
            for (int i = rs; i <= re; ++i) {
                ans.push_back(matrix[i][ce]);
            }
            --ce;

            if (ans.size() == mn) break;

            // right -> left
            for (int i = ce; i >= cs; --i) {
                ans.push_back(matrix[re][i]);
            }
            --re;

            // down -> top
            for (int i = re; i >= rs; --i) {
                ans.push_back(matrix[i][cs]);
            }
            ++cs;
        }

        return ans;
    }
};