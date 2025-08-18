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
        unordered_map<int, int> intervals;
        unordered_set<int> seen;
        int longest = 0;

        for (int num : nums) {
            // skip exist one
            if (seen.count(num)) continue;

            seen.insert(num);
            auto next = intervals.find(num+1);
            auto prev = intervals.find(num-1);
            int start, end, prevEnd, nextEnd;

            // concate 2 intervals
            if (next != intervals.end() && prev != intervals.end()) {
                prevEnd = prev->second, nextEnd = next->second;
                start = min(num-1, prevEnd), end = max(num+1, nextEnd);
                // remvoe old ones
                intervals.erase(num-1); intervals.erase(prevEnd);
                intervals.erase(num+1); intervals.erase(nextEnd);
            } else if (next != intervals.end()) {
                nextEnd = next->second;
                start = min(num, nextEnd), end = max(num+1, nextEnd);
                // remove old ones
                intervals.erase(num+1); intervals.erase(nextEnd);
            } else if (prev != intervals.end()) {
                prevEnd = prev->second;
                start = min(num-1, prevEnd), end = max(num, prevEnd);
                // remove old ones
                intervals.erase(num-1); intervals.erase(prevEnd);
            } else {
                start = num, end = num;
            }

            // insert new merged intervals
            intervals[start] = end;
            intervals[end] = start;

            longest = max(longest, (end - start) + 1);
        }

        return longest;
    }
};


