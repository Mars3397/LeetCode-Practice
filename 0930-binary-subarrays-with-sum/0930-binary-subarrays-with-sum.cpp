class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        long long sum = 0;                 // 前綴和
        int ans = 0;
        unordered_map<long long,int> freq; // sum -> 次數
        freq.reserve(nums.size() * 2);
        freq[0] = 1;                       // 空前綴

        for (int x : nums) {
            sum += x;
            if (auto it = freq.find(sum - goal); it != freq.end())
                ans += it->second;         // 有幾個 sum-k
            ++freq[sum];
        }
        return ans;
    }
};