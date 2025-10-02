/*
Approach
1. first sort the vector to allow we to use 2 pointer search
2. for all num in nums: find cloest triplet with 2 pointers in [i+1...n]
3. record the sum of triplet which is the cloest to the target

Analysis
1. time: O(nlogn) + O(n^2) = O(n^2)
2. space: O(1)
*/


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // sort nums
        sort(nums.begin(), nums.end());


        // find triplet
        int n = nums.size(), closestSum = 0, minDiff = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int l = i+1, r = n-1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                // record closestSum
                if (abs(target - sum) < minDiff) {
                    minDiff = abs(target - sum);
                    closestSum = sum;
                }

                if (sum == target) {
                    return target;
                } else if (sum < target) {
                    ++l;
                } else {
                    --r;
                }
            }
        }

        return closestSum;
    }
};