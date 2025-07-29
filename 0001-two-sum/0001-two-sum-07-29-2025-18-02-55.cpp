class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        int n = nums.size();
        umap[nums[0]] = 0;

        for (int i = 1; i < n; ++i) {
            int comp = target - nums[i];
            if (umap.count(comp)) return { i, umap[comp] };

            umap[nums[i]] = i;
        }

        return { 0, 0 };
    }
};