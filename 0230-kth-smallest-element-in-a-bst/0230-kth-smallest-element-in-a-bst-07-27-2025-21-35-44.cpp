/*
Approach
1. perform inorder traversal until kth element

Follow Up
1. add a propety called lessCount to store the number of nodes whose number are less than current
2. improve the average look up time to O(logn)

Analysis
1. time: O(k)
2. space: O(h) where h = the maximum hegiht to kth node
*/

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode *cur = root;

        while (cur || !stk.empty()) {
            // reach until the leftmost node
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }

            // inorder
            cur = stk.top(); stk.pop();
            if (--k == 0) return cur->val;

            // turn right
            cur = cur->right;
        }

        return 0;
    }
};