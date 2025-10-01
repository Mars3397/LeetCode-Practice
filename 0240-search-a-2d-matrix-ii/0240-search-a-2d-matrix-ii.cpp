/*
Approach
1. DFS from the left upper corner of matrix
2. push all numbers that are less than target into stack
3. pop them out and check their right and down cells
4. repeat steps 2 until find target or no numbers in stack to explore

Analysis
1. time: O(m * n)
2. space: O(m * n)

Optimization
1. binary search for each row -> time complexity become O(m * logn)
2. search each rows until the first number in the row is bigger than target
*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < m; ++i) {
            // early break
            if (matrix[i][0] > target) break;

            // binary search
            int l = 0, r = n-1;
            while (l <= r) {
                int mid = l + (r - l) / 2;

                if (matrix[i][mid] == target) return true;
                else if (matrix[i][mid] < target) l = mid + 1;
                else r = mid - 1;
            }
        }

        return false;
    }
};