/*
Approach
1. recursively to return the depth of left and right sub tree
2. if the difference between them exceed 1 -> set flag to false

Analysis
1. time: O(n) where n = number of nodes in the tree
2. space: O(h) where h = height of the tree
*/

class Solution {
private:
    bool balanced = true;

    int depth(TreeNode* n) {
        if (!n || !balanced) return 0;

        int leftDepth = depth(n->left);
        int rightDepth = depth(n->right);

        if (abs(leftDepth - rightDepth) > 1) {
            balanced = false;
            return 0;
        }

        return max(leftDepth, rightDepth) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        depth(root);

        return balanced;
    }
};