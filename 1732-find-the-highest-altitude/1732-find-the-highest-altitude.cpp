/*
Approach
1. track the current altitude for each points
2. record the max altitude while traveling through all points

Analysis
1. time: O(n)
2. space: O(1)
*/


class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAltitude = 0, curAltitude = 0;

        for (int g : gain) {
            curAltitude += g;
            maxAltitude = max(maxAltitude, curAltitude);
        }

        return maxAltitude;
    }
};