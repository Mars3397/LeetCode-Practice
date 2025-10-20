class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n-2*k; ++i) {
            bool found = true;
            for (int j = i+1; j < i + k; ++j) {
                if (nums[j] <= nums[j-1]) {
                    found = false;
                    break;
                }
            }

            if (!found) continue;

            found = true;
            for (int j = i + k + 1; j < i + 2 * k && j < n; ++j) {
                if (nums[j] <= nums[j-1]) {
                    found = false;
                    break;
                }
            }

            if (found) return true;
        }

        return false;
    }
};