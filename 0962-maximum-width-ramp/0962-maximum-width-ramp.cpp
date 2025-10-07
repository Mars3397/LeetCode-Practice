/*
Approach
1. we want to find minimum on the left -> only care about smaller one
2. monotonic stack -> keep track of smaller value
3. we find ramp from the right and record the max width of ramp


*/


class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> stk; // store the index of new minimal
        int n = static_cast<int>(nums.size());

        // construct monotonic stack
        for (int i = 0; i < n; ++i) {
            if (stk.empty() || nums[i] < nums[stk.top()]) {
                stk.push(i);
            }
        }

        int maxWidth = 0;
        for (int i = n-1; i >= 0 && !stk.empty(); --i) {
            while (!stk.empty() && nums[i] >= nums[stk.top()]) {
                maxWidth = max(maxWidth, i - stk.top());
                stk.pop();
            }
        }

        return maxWidth;
    }
};