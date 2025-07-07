/*
Conditions
1. |left|-----|mid|--O--|right|
2. |left|--O--|mid|-----|right|


Approach
1. use binary search with additional check to solve this problem

Analysis
1. time: O(logn) where n = nums.size()
2. space: O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            
            if (nums[left] <= nums[mid]) { // condition 1
                if (nums[left] <= target && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            } else { // condition 2
                if (nums[mid] < target && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
        }

        return -1;
    }
};