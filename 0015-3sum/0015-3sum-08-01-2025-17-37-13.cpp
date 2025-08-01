/*
Approach
1. find complement in a set where checked number are pushed to
2. only push checked number to set to avoid reusing

Analysis
1. time: O(n^2) where n = nums.size()
2. space: O(n) where n = nums.size()
*/

class Solution {
private:
    // make each number appears no more than three times
    void trimNums(vector<int> &nums) {
        unordered_map<int, int> freq;

        int write = 0, n = nums.size();
        for (int read = 0; read < n; ++read) {
            if (!freq.count(nums[read])) {
                freq[nums[read]] = 1;
                nums[write++] = nums[read];
            } else if (freq[nums[read]] < 3) {
                nums[write++] = nums[read];
                ++freq[nums[read]];
            }
        }

        nums.resize(write);
    }

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        // trim the nums vector to make no number in nums appears more than three times
        trimNums(nums);
        int n = nums.size();

        // prepare complements & seen set
        unordered_set<string> seen;
        unordered_set<int> complements;
        complements.insert(nums[0]);

        for (int i = 1; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                int target = 0 - nums[i] - nums[j];
                if (complements.count(target)) {
                    vector<int> v = { target, nums[i], nums[j] };
                    sort(v.begin(), v.end());
                    string hash = to_string(v[0]) + to_string(v[1]) + to_string(v[2]);
                    if (!seen.count(hash)) {
                        ans.push_back({ target, nums[i], nums[j] });
                        seen.insert(hash);
                    }
                }
            }

            // add checked number to complemets set
            complements.insert(nums[i]);
        }

        return ans;
    }
};