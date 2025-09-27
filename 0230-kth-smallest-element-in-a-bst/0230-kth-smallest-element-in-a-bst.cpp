/*
Approach
1. the inorder traversal of a binary search tree will be traverse from small to large
2. perform the inorder traversal until k and return its value

Analysis
1. time: O(k)
2. space: O(n)
*/


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        unordered_set<TreeNode*> seen;
        vector<TreeNode*> stk;
        stk.push_back(root);

        while (!stk.empty()) {
            // push all the sub-left node
            while (stk.back()->left && !seen.count(stk.back()->left)) {
                stk.push_back(stk.back()->left);
            }

            // reach the leftest node -> check its position
            TreeNode *node = stk.back(); stk.pop_back();
            if (--k == 0) return node->val;
            seen.insert(node);

            // push the right if has
            if (node->right) stk.push_back(node->right);
        }

        // should not execute to here
        return 0;
    }
};