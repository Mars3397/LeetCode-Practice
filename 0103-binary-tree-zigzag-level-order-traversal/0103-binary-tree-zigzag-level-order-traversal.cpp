/*
Approach
1. just perform the level order traversal but reverse the level order alternatively


*/


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // declaration
        vector<vector<int>> result;
        bool rev = false;
        
        // prepare level order traversal queue
        queue<TreeNode*> q;
        if (root) q.push(root);

        // level order traversal
        while (!q.empty()) {
            // level size will be the current size of queue
            int levelSize = q.size();
            vector<int> level(levelSize);
            for (int i = 0; i < levelSize; ++i) {
                TreeNode *n = q.front();
                level[i] = n->val;

                // push the children
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);

                // pop out
                q.pop();
            }

            // check for reverstion
            if (rev) reverse(level.begin(), level.end());
            rev = !rev;

            // push to result
            result.push_back(move(level));
        }

        return result;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */