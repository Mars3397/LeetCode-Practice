/*
Approach
1. use a hash map to find the complement
2. iterate through the array to find complement in hash map

Aanlysis
1. time: O(n) where n = nums.size()
2. space: O(n) where n = nums.size()
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // (number, index)

        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            // find complement
            auto f = seen.find(target - nums[i]);
            
            // return when found
            if (f != seen.end()) return { i, f->second };

            // insert the seen number and index pair
            seen[nums[i]] = i;
        }

        // default return (should not execute to here)
        return {};
    }
};