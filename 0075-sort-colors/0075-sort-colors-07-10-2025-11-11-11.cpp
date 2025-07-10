class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, n = nums.size();

        for (int num : nums) {
            if (num == 0) ++red;
            else if (num == 1) ++white;
        }

        for (int i = 0; i < n; ++i) {
            if (red) {
                nums[i] = 0;
                --red;
            } else if (white) {
                nums[i] = 1;
                --white;
            } else {
                nums[i] = 2;
            }
        }
    }
};