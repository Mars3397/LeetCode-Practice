/*
Approach
1. 

*/

class Solution {
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
        if (pr < pl) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[pl]);
        if (pl == pr) return root;

        for (int i = il; i <= ir; ++i) {
            if (inorder[i] == preorder[pl]) {
                root->left = build(preorder, inorder, pl+1, pl+(i-il), il, i-1);
                root->right = build(preorder, inorder, pl+(i-il)+1, pr, i+1, ir);
                break;
            }
        }

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size()-1, 0, preorder.size()-1);
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