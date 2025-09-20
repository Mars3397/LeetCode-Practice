/*
Approach
1. push the numbers in nums1 to a unordered_set
2. iterate through nums2 to find number in the set
3. if found -> push to result vector

Analysis
1. time: O(m + n) where m = nums1.size() and n = num2.size()
2. space: O(m + n) where m = nums1.size() and n = num2.size()
*/


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        vector<int> result;

        for (int num : set2) {
            if (set1.count(num)) {
                result.push_back(num);
            }
        }

        return result;
    }
};