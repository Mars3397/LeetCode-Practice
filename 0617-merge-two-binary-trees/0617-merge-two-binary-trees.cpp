/*
Approach
1. use tree 1 as the return tree -> add tree2 to it
2. do it recursively

*/

class Solution {
private:
    void merge(TreeNode *n1, TreeNode *n2) {
        // merge left tree
        if (n2->left) {
            if (!n1->left) n1->left = new TreeNode(n2->left->val);
            else n1->left->val += n2->left->val;
            merge(n1->left, n2->left);
        }

        // merge right tree
        if (n2->right) {
            if (!n1->right) n1->right = new TreeNode(n2->right->val);
            else n1->right->val += n2->right->val;
            merge(n1->right, n2->right);
        }
    }

public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;

        root1->val += root2->val;
        
        merge(root1, root2);

        return root1;
    }
};