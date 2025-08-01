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
private:
    stack<int> maxStk;
    int good = 0;

    void DFS(TreeNode* node) {
        if (!node) return;

        if (maxStk.empty() || node->val >= maxStk.top()) {
            ++good;
            maxStk.push(node->val);
        }

        DFS(node->left);
        DFS(node->right);

        if (node->val == maxStk.top()) maxStk.pop();

        return;
    }

public:
    int goodNodes(TreeNode* root) {
        DFS(root);

        return good;
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