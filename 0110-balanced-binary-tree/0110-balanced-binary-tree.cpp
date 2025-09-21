/*
Approach
1. check the height of left subtree and right subtree for each node
2. once the difference between them exceed 1 -> consider as inbalanced
3. implement using recursive function

Analysis
1. time: O(n) where n = number of nodes in the tree
2. space: O(h) where h = the height of the tree (the depth of resursive function)
*/

class Solution {
private:
    // return -1 for inbalanced tree, positive height for balanced tree
    int height(TreeNode *node) {
        if (!node) return 0;

        // calculate the height of left subtree 
        int l = height(node->left);
        if (l == -1) return -1;

        // calculate the height of right subtree 
        int r = height(node->right);
        if (r == -1) return -1;

        // check is height balanced or not
        if (abs(l - r) > 1) return -1;

        return 1 + max(l, r); // return the positive height (maximum between left and right + 1)
    }

public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};