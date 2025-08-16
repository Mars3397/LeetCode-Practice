/*
Approach
1. recursively to construct -> divide into left, root, right
2. construct left and right and return root
3. the start of preorder will be the root, and the nodes before root in inorder is left subtree

Example.
[3,9,20,15,7] / [9,3,15,20,7]
[9] [3] [20,15,7] / [9] [3] [15,20,7]
[9] [3] [15] [20] [7] / [9] [3] [15] [20] [7]

Analysis
1. time: O(n) where n = number of nodes in the tree
2. space: O(h) where h = height of the tree
*/

class Solution {
private:
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
        cout << pl << " " << pr << " " << il << " " << ir << endl;
        if (pl == pr) return new TreeNode(preorder[pl]);
        if (pl > pr) return nullptr;

        int ls = 0; // left subtree size
        for (int i = il; i <= ir; ++i) {
            if (inorder[i] == preorder[pl]) {
                ls = i - il;
                break;
            }
        }

        TreeNode *subRoot = new TreeNode(preorder[pl]);
        subRoot->left = construct(preorder, inorder, pl+1, pl+ls, il, il+ls-1);
        subRoot->right = construct(preorder, inorder, pl+ls+1, pr, il+ls+1, ir);

        return subRoot;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return construct(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};