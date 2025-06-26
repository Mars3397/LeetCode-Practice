/*
Approach
1. use a queue to help me traverse in level order
2. push the root to queue, then push all children to queue
3, repeat until queue is empty

*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root) q.push(root);

        while (!q.empty()) {
            vector<int> inLevel;

            int n = q.size(); // current level size
            for (int i = 0; i < n; ++i) {
                TreeNode *n = q.front(); q.pop();
                inLevel.push_back(n->val);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            res.push_back(inLevel);
        }

        return res;
    }
};