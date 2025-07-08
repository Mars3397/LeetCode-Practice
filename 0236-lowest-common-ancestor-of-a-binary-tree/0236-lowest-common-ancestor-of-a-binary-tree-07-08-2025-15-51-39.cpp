/*
Approach
1. LCA has 3 format: left + right, left + root, root + right
2. use bottom up approach to propagate existences

*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;
        if (root == p || root == q) return root;

        TreeNode *inLeft = lowestCommonAncestor(root->left, p, q);
        TreeNode *inRight = lowestCommonAncestor(root->right, p, q);

        if (inLeft && inRight) return root;

        return inLeft ? inLeft : inRight;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */