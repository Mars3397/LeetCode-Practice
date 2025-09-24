/*
Approach
1. put the larger density box first

Analysis
1. time: O(n)
2. space: O(1)
*/


class Solution {
private:
    static bool densityCompare(const vector<int> &a, const vector<int> &b) {
        return a[1] >= b[1];
    }

public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), densityCompare);

        int cnt = 0, idx = 0, truck = 0, n = boxTypes.size();

        while (idx < n && truck < truckSize) {
            truck += boxTypes[idx][0];
            cnt += boxTypes[idx][0] * boxTypes[idx][1];
            ++idx;
        }

        if (truck == truckSize) return cnt;

        // remove the overloaded box
        --idx;
        while (truck > truckSize) {
            --truck;
            cnt -= boxTypes[idx][1];
        }

        return cnt;
    }
};