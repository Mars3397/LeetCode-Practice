/*
Approach
1. use DFS to iterate through the tree
2. record the current max in a stack
3. if the node >= stack top -> good count + 1

Analysis
1. time: O(n) where n = number of nodes in the tree
2. space: O(h) where h = the height of tree
*/

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }

private:
    int dfs(TreeNode* node, int maxSoFar) {
        if (!node) return 0;

        int good = 0;
        if (node->val >= maxSoFar) ++good;

        maxSoFar = max(maxSoFar, node->val);
        good += dfs(node->left, maxSoFar);
        good += dfs(node->right, maxSoFar);

        return good;
    }
};
