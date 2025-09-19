/*
Approach
1. recursive approach
2. prop path string from parent to child
3, append value and then pass to child
4. push to result vector if reach leaf node

Analysis
1. time: O(n * h) where n = number of nodes in the tree, h = the height of the tree
2. space: O(h) where h = the height of the tree
*/

class Solution {
private:
    vector<string> result;

    void recordPath(TreeNode* node, string path) {
        if (!node) return;

        if (path != "") path += "->";
        path += to_string(node->val);

        // reach leaf node
        if (!node->left && !node->right) {
            result.push_back(path);
            return;
        }

        recordPath(node->left, path);
        recordPath(node->right, path);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        // recursive to form path
        recordPath(root, "");

        return result;
    }
};