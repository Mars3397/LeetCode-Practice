class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int write = 0, n = nums.size();

        for (int read = 1; read < n; ++read) {
            if (nums[read] == nums[write]) continue;

            nums[++write] = nums[read];
        }

        return write + 1;
    }
};