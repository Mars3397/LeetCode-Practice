/*
Approach
1. distribute to the class which can boost pass ratio most -> max potential increase by the following expression
2. store all class to a priority queue (smaller total student class on the top)
3. distribute extra students to the top of queue
4. calculate the average pass ratio

* potential increase: (x+1)/(y+1) - (x/y) = (xy+y)/(yy+y) - (xy+x)/(yy+y) = (y - x) / (yy + y)

Analysis
1. time: O(nlogn + klogn) where n = classes.size() and k = extraStudents
2. space: O(n)
*/


class Solution {
private:
    struct smallClasses {
        bool operator()(const vector<int> &a, const vector<int> &b) {
            double ax = static_cast<double>(a[0]), ay = static_cast<double>(a[1]);
            double bx = static_cast<double>(b[0]), by = static_cast<double>(b[1]);
            double increaseA = (ay - ax) / (ay * ay + ay);
            double increaseB = (by - bx) / (by * by + by);

            return increaseA < increaseB;
        }
    };

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // declare a priority queue with smaller total number of students first
        priority_queue<vector<int>, vector<vector<int>>, smallClasses> pq(classes.begin(), classes.end());

        // distribute extra students to class with fewest student (if the pass ration is not 100%) 
        double ratioSum = 0.0;
        while (extraStudents && !pq.empty()) {
            vector<int> top = pq.top(); pq.pop();
            if (top[0] == top[1]) {
                ratioSum += 1.0;
            } else {
                ++top[0];
                ++top[1];
                --extraStudents;
                pq.push(top);
            }
        }

        // calculate the avg
        while (!pq.empty()) {
            vector<int> top = pq.top(); pq.pop();
            ratioSum += static_cast<double>(top[0]) / top[1];
        }

        return ratioSum / classes.size();
    }
};
