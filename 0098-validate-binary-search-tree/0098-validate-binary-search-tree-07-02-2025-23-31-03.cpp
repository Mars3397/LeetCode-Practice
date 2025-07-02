/*
Approach
1. perform inorder traversal to a valid bst should get a increasing sequence

Analysis
1. time: O(n) where n = number of nodes in the tree
2. space: O(h) where h = the height of the tree
*/


class Solution {
private:
    bool isValid = true, isFirst = true;
    int lastOne = 0;

    void inorderTraversal(TreeNode *node) {
        if (!node) return;

        inorderTraversal(node->left);

        if (isFirst) isFirst = false;
        else isValid = isValid && lastOne < node->val;

        if (!isValid) return;
        lastOne = node->val;

        inorderTraversal(node->right);
    }

public:
    bool isValidBST(TreeNode* root) {
        inorderTraversal(root);

        return isValid;
    }
};