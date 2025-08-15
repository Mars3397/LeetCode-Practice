/*
Approach
1. iterative to push node to queue
2. the size of queue will be the size of current level

Analysis
1. time: O(n) where n = number of nodes in the tree
2. space: O(h) where h = height of the tree
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q; 
        q.push(root);

        while (!q.empty()) {
            int levelCount = q.size();
            vector<int> v; v.reserve(levelCount);

            for (int i = 0; i < levelCount; ++i) {
                v.push_back(q.front()->val);
                if (q.front()->left) q.push(q.front()->left);
                if (q.front()->right) q.push(q.front()->right);
                q.pop();
            }

            ans.push_back(v);
        }


        return ans;
    }
};