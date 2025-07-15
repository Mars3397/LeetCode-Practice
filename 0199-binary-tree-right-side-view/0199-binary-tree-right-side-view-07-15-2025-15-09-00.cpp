/*
Approach
1. use a level order traversal to iterate through the tree
2. and push the last element of a level to result vector

*/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        vector<int> view;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            // push the next level
            int n = q.size(); // the size of current level
            for (int i = 0; i < n-1; ++i) {
                TreeNode* t = q.front(); q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }

            // push the last element of a level to result vector
            TreeNode* last = q.front(); q.pop();
            view.push_back(last->val);

            // still need to push last element's child
            if (last->left) q.push(last->left);
            if (last->right) q.push(last->right);
        }

        return view;
    }
};