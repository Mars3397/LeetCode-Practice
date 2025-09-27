/*
Approach
1. check wether the array is in non-deceasing order (cur is >= prev)
2. also there are at most one turning points (nums[i] < nums[0]) 

Analysis
1. time: O(n) where n = nums.size()
2. space: O(1)
*/


class Solution {
public:
    bool check(vector<int>& nums) {
        bool isRotated = false;
        int prev = nums[0], n = nums.size();

        for (int i = 1; i < n; ++i) {
            if (nums[i] < prev) {
                if (nums[i] > nums[0]) return false;
                if (!isRotated) isRotated = true;
                else return false;
            }

            if (isRotated && nums[i] > nums[0]) return false;

            prev = nums[i];
        }

        return true;
    }
};