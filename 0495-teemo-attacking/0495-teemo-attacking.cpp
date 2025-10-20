class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = 0, cur = 0, n = timeSeries.size();

        for (int i = 0; i < n; ++i) {
            if (cur > timeSeries[i]) {
                int diff = cur - timeSeries[i];
                total -= diff;
                cur = timeSeries[i];
            }

            total += duration;
            cur = timeSeries[i] + duration;
        }

        return total;
    }
};