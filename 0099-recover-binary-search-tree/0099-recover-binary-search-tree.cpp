/*
Approach
1. inorder traveral to find misplaced values
2. prev.val > cur.val -> misplaced values
3. there are at most 2 pairs: swap with adjacent -> 1, swap with non-adjacent -> 2
4. if found 1 -> swap the pair, if found 2 -> swap first prev with second cur

Analysis
1. time: O(n)
2. space: O(n)
*/


class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode *prev = nullptr, *cur = root;
        TreeNode *targetA, *targetB;
        bool isFirst = true;

        // iterative inorder traversal
        while (cur || !stk.empty()) {
            // reach the leftest node
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }

            // pop current leftest
            cur = stk.top(); stk.pop();

            // check misplaced value pair
            if (prev && prev->val > cur->val) {
                if (isFirst) {
                    targetA = prev;
                    isFirst = false;
                }
                targetB = cur;
            }

            // update prev and cur
            prev = cur;
            cur = cur->right;
        }

        swap(targetA->val, targetB->val);
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