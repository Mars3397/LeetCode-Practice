/*
Approach
1. we can solve this with two pointers
2. one start from the begin, another one start from the end
3. record current maximum and move the shorter one

Analysis
1. time: O(n) where n = height.size()
2. space: O(1)
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maximum = 0;

        while (l < r) {
            maximum = max(maximum, (r - l) * min(height[l], height[r]));

            if (height[l] < height[r]) ++l;
            else --r;
        }

        return maximum;
    }
};