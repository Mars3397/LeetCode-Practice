/*
Approach
1. deal with the diagnal line by line
2. push all element in the same diagnal to a vector than sort it
3. put the sorted numbers back to original matrix
4. note: same diagnal line element grid[i][j] will have same j - i

Analysis
1. time: O(n^2 * logn)
2. space: O(1)
*/


class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        // declaration
        int n = grid.size();
        vector<int> storage; storage.reserve(n);
        
        // bottom-left triangle -> in non-increasing order
        for (int i = 0; i < n; ++i) {
            // clear the storage before handle a new diagnal
            storage.clear();

            // push same diagnal element to storage
            int r = i, c = 0;
            while (r < n) {
                storage.push_back(grid[r][c]);
                ++r; ++c;
            }

            // sort the storage
            sort(storage.begin(), storage.end(), greater<int>());

            // fill the sorted numbers to original matrix
            int fillR = i, fillC = 0;
            for (int num : storage) {
                grid[fillR][fillC] = num;
                ++fillR; ++fillC;
            }
        }

        // top-right triangle -> in non-decreasing order
        for (int i = 1; i < n; ++i) {
            // clear the storage before handle a new diagnal
            storage.clear();

            // push same diagnal element to storage
            int r = 0, c = i;
            while (c < n) {
                storage.push_back(grid[r][c]);
                ++r; ++c;
            }

            // sort the storage
            sort(storage.begin(), storage.end());

            // fill the sorted numbers to original matrix
            int fillR = 0, fillC = i;
            for (int num : storage) {
                grid[fillR][fillC] = num;
                ++fillR; ++fillC;
            }
        }

        return grid;
    }
};