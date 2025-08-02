/*
Approach
1. calculate the height of each nodes in the tree
2. when returning at each node, check the diameter of the leftest nodes and rightest nodes
3. save the maximum in a variable

Analysis
1. time: O(n) where n = number of nodes in the tree
2. space: O(h) where h = height of the tree
*/


class Solution {
private:
    int diameter = 0;

    int treeHeight(TreeNode *node) {
        if (!node) return 0;

        int leftSubTreeHeight = treeHeight(node->left);
        int rightSubTreeHeight = treeHeight(node->right);
        int curDiameter = leftSubTreeHeight + rightSubTreeHeight;

        diameter = max(diameter, curDiameter);

        return max(leftSubTreeHeight, rightSubTreeHeight) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        treeHeight(root);

        return diameter;
    }
};