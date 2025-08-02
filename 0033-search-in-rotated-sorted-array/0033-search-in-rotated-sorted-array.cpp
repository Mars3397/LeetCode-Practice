/*
Approach
1. solve with binary search (handle some special cases)
2. case 1: |--o--x-----|
3. case 2: |-----x--o--|

*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < nums[l]) { // case 1
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else { // case 2
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }

        return -1;
    }
};