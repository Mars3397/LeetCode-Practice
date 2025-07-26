/*
Approach
1. store the tasks in a priority queue
2. choose the most waiting tasks label for each execution slot

*/


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // calculate waiting tasks count for each task label
        vector<int> labelCount(26);
        for (char c : tasks) {
            ++labelCount[c-'A'];
        }

        // push them to a prority queue
        priority_queue<int> pq;
        for (int cnt : labelCount) {
            if (cnt > 0) pq.push(cnt);
        }

        // execute
        vector<int> executed;
        int require = 0, slot = n + 1, lastSlot = 0;
        while (!pq.empty()) {
            // reset lastSlot
            lastSlot = 0;

            // execute executable tasks (task in priority queue)
            while (slot > 0 && !pq.empty()) {
                executed.push_back(pq.top()-1);
                pq.pop();
                --slot;
                ++lastSlot;
            }

            // add
            require += n + 1;

            // reset
            slot = n + 1;
            while (!executed.empty()) {
                if (executed.back() > 0) pq.push(executed.back());
                executed.pop_back();
            }
        }
        
        return require - (n + 1 - lastSlot);
    }
};