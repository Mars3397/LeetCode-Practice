class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), count = 0;
        vector<int> prefix(n, 0);

        // handle first one
        prefix[0] = nums[0];
        if (nums[0] == k) ++count;

        for (int i = 1; i < n; ++i) {
            // update prefix
            prefix[i] = prefix[i-1] + nums[i];
            if (prefix[i] == k) ++count;
            
            // all subarray sum end in index i
            for (int j = 0; j < i; ++j) {
                if (prefix[i] - prefix[j] == k) ++count;
            }
        }

        return count;
    }
};