/*
Approach
1. store the sequence as intervals (start, end) in an unordered_map
2. iterate through the nums to push and merge intervals while recording the maximum
3. return the maximum

Anaysis
1. time: O(n)
2. space: 
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int best = 0;

        for (int x : s) {
            // 只有在 x 是一段的起點（x-1 不存在）時才延伸
            if (!s.count(x - 1)) {
                int y = x;
                while (s.count(y)) ++y;          // 數到最右 y（第一個不存在的位置）
                best = max(best, y - x);          // 長度 = y - x
            }
        }
        return best;
    }
};
