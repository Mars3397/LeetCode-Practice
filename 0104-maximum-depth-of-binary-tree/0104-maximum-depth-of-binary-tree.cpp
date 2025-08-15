/*
Approach
1. use a recursive approach to count the max depth

Analysis
1. time: O(n) where n = number of nodes in the tree
2. space: O(h) where h = height of the tree
*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};