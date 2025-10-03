/*
Approach
1. brute force: cehck every pairs -> O(n^2)
2. sorting + two pointer: O(nlogn) in time and O(1) in space
3. store complement in unordered_map: O(n) in time and space
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // declare a hash table to store the complements
        unordered_map<int, int> complements; // (number, index)

        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            // find complement in complements hash table
            int complement = target - nums[i];
            auto f = complements.find(complement);
            if (f != complements.end()) {
                // return index when found
                return { i, f->second };
            }

            // push number to the complement map
            // push after find to prevent multiple use of a number
            complements[nums[i]] = i;
        }

        // should not be here
        return {};
    }
};