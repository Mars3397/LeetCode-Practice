/*
Approach
1. use a recursive approach
2. if root == subRoot -> match all the descendants
3. if root != subRoot -> try to match for root->left or root->right

Analysis
1. time: O(n) where n = unmber of node in the root
2. space: 
*/
class Solution {
private:
    bool isSame(TreeNode *n1, TreeNode *n2) {
        if (!n1 && !n2) return true;
        if (!n1 || !n2) return false;
        if (n1->val != n2->val) return false;
        return isSame(n1->left, n2->left) && isSame(n1->right, n2->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (isSame(root, subRoot)) return true;
        if (!root) return false;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};