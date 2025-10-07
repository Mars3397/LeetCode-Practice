class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());  // O(n log n)

        for (int i = 0; i < n; ++i) {
            // 跳過重複固定值
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = -nums[i];
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    // 跳過重複 left/right
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;
                    ++left;  --right;
                }
                else if (sum < target) ++left;
                else --right;
            }
        }
        return res;
    }
};
