/*
Approach
1. declare two unordered_maps for points to be query from x-axis and y-axis
2. when counting -> find squares along given point's x-axis and y-axis

Analysis
1. time: 
2. space: 
*/

class DetectSquares {
private: 
    unordered_map<int, unordered_map<int, int>> xAxisMap, yAxisMap;

public:
    DetectSquares() {
        xAxisMap.clear();
        yAxisMap.clear();
    }
    
    void add(vector<int> point) {
        ++xAxisMap[point[0]][point[1]];
        ++yAxisMap[point[1]][point[0]];
    }
    
    int count(vector<int> point) {
        int cnt = 0;

        for (auto [y, cy] : xAxisMap[point[0]]) {
            if (y == point[1]) continue; // skip squares whose area = 0

            // 2 directions
            int dx = abs(point[1] - y), x1 = point[0] + dx, x2 = point[0] - dx;

            // direction 1
            if (yAxisMap[point[1]].count(x1) && xAxisMap[x1].count(y)) {
                cnt += cy * yAxisMap[point[1]][x1] * xAxisMap[x1][y];
            }

            // direction 2
            if (yAxisMap[point[1]].count(x2) && xAxisMap[x2].count(y)) {
                cnt += cy * yAxisMap[point[1]][x2] * xAxisMap[x2][y];
            }
        }

        return cnt;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
