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
        unordered_map<int,int> len;  // 端點 -> 區間長度
        int best = 0;
        for (int x : nums) {
            if (len.count(x)) continue;          // 已處理過，略過重複
            int L = len.count(x - 1) ? len[x - 1] : 0;
            int R = len.count(x + 1) ? len[x + 1] : 0;
            int tot = L + 1 + R;
            len[x] = tot;                         // 中間點隨便設，關鍵是端點
            len[x - L] = tot;                     // 更新左端點
            len[x + R] = tot;                     // 更新右端點
            best = max(best, tot);
        }
        return best;
    }
};
