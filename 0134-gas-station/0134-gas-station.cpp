/*
Approach
1. we should choose to start at the station that can fill tank with most gas within the sequence of station

Analysis
1. time: O(n) where n = gas.size()
2. space: O(1)
*/


class Solution { 
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        for (int cur = 0, start, tank; cur < n; ) {
            start = cur;
            tank = 0;

            // travel to farthest station
            while (tank >= 0 && cur - start < n) {
                tank += gas[cur % n];
                tank -= cost[cur % n];
                ++cur;
            }

            if (tank >= 0) return start;
        }

        return -1;
    }
};