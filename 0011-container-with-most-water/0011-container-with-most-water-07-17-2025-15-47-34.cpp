/*
Approach
1. solve this using two pointer + greed
2. move the smaller one between height[left] an height[right]

Analysis
1. time: O(n) where n = height.size()
2. space: O(1)
*/


class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1, most = 0;

        while (left < right) {
            int cur = (right - left) * min(height[left], height[right]);
            most = max(most, cur);

            if (height[left] < height[right]) ++left;
            else --right;
        }

        return most;
    }
};