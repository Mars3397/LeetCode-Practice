/*
Approach
1. we can check wether the inorder traversal is strictly incresing
2. implement a iterative approach while make sure the previous one is smaller than current

*/


class Solution {
private: 
    bool valid = true, isFirst = true;
    int prev = 0;

    void inorder(TreeNode* n) {
        if (!n) return;

        inorder(n->left);
        
        if (isFirst) {
            prev = n->val;
            isFirst = false;
        } else if (prev >= n->val) {
            valid = false;
            return;
        } else {
            prev = n->val;
        }

        inorder(n->right);
    }

public:
    bool isValidBST(TreeNode* root) {
        inorder(root);

        return valid;
    }
};