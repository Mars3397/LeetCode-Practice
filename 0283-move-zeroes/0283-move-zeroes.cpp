class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int write = 0, n = nums.size();
        for (int read = 0; read < n; ++read) {
            if (nums[read] != 0) {
                nums[write++] = nums[read];
            }
        }

        while (write < n) {
            nums[write++] = 0;
        }

        return;
    }
};