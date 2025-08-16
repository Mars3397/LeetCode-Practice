/*
Approach
1. the whole timeline can be divide into 2 parts: backbone + tail
2. backbone = form with the maxFreq task be at the start of each time slot
3. tail = last one of each maxFreq tasks + tasks that exceed the capacity of backbone

Example: tasks = ["A","C","A","B","D","B"], n = 1
A B _   A B _   A B
|- backbone -|  |-tail-|

Analysis
1. time: O(n) where n = tasks.size()
2. space: O(1)
*/


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // count the frequency of each task while record the max frequency
        int maxFreq = 0;
        vector<int> freq(26, 0);
        for (char c : tasks) {
            maxFreq = max(maxFreq, ++freq[c-'A']);
        }

        // count how many tasks has the same frequency as maxFreq
        int maxFreqCount = 0;
        for (int f : freq) {
            if (f == maxFreq) ++maxFreqCount;
        }

        // two parts: backbone + tail
        int ans = (maxFreq - 1) * (n + 1) + maxFreqCount;

        return max(ans, (int)tasks.size());
    }
};