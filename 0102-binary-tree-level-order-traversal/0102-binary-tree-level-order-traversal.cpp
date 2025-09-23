/*
Approach
1. use a queue to hold nodes in level order
2. after push all the children of current level in to queue, the size of queue will be the size of next level
3. push level by level to result vector

Analysis
1. time: O(n) where n = number of nodes in the tree
2. space: O(n) where n = number of nodes in the tree
*/


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        // declaration
        queue<TreeNode*> q;
        vector<vector<int>> result;

        // initialization
        q.push(root);

        // push level by level
        while (!q.empty()) {
            // number of nodes in current level
            int n = q.size();
            vector<int> level(n);

            for (int i = 0; i < n; ++i) {
                TreeNode *node = q.front(); q.pop();
                level[i] = node->val;

                // push child to queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

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