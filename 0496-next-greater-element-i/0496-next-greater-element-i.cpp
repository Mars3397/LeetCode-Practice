/*
Approach
1. first construct the next greater element vector for each number in nums2
2. construct: maintain a stack to store unfilled number (haven't see greater number)
3. for each element: check it is greater than elements in stack or not and fill their next greater number
4. for each number in nums1: push their next greater element to result vector

Analysis
1. time: O(n)
2. space: O(n)
*/


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // declaration and initialization
        int n1 = nums1.size(), n2 = nums2.size();
        stack<int> stk;
        unordered_map<int, int> nextGreater; nextGreater.reserve(n2);
        
        // find next greater element for all numbers in nums2
        for (int i = 0; i < n2; ++i) {
            // find whose next greater element in stack is nums2[i]
            while (!stk.empty() && nums2[i] > stk.top()) {
                nextGreater[stk.top()] = nums2[i];
                stk.pop();
            }

            // push nums2[i] to stk waiting for its next greater element
            stk.push(nums2[i]);
        }

        // set the remain numbers in the stack to no next greater element
        while (!stk.empty()) {
            nextGreater[stk.top()] = -1;
            stk.pop();
        }

        // fetch result for all numbers in nums1
        vector<int> result(n1, -1);
        for (int i = 0; i < n1; ++i) {
            result[i] = nextGreater[nums1[i]];
        }

        return result;
    }
};