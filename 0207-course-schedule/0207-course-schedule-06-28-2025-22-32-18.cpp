/*
Approach
1. construct a graph using 2D vector to record edges from prerequisites -> courses
2. count total number of in edge for each courses
3. start with zero in edge courses -> minus one for their neighbor
4. push no in degree courses to queue to explore (cehck can reach all courses or not)

Analysis
1. time: O(numCourses + e) where e = total number of edges = prerequisites.size()
2. space: O(numCourses + e) where e = total number of edges = prerequisites.size()
*/


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjs(numCourses, vector<int>()); // adjs[i] = the courses whose prerequisites has course i
        vector<int> inDeg(numCourses, 0); // number of prerequisites of course i

        for (auto &p : prerequisites) {
            adjs[p[1]].push_back(p[0]);
            ++inDeg[p[0]];
        }

        // store courses whose indeg == 0 
        queue<int> q;

        // start with no prerequisites courses (indeg = 0)
        for (int i = 0; i < numCourses; ++i) {
            if (inDeg[i] == 0) q.push(i);
        }

        int finishedCourses = 0;
        while (!q.empty()) {
            int c = q.front(); q.pop();
            ++finishedCourses;

            for (int next : adjs[c]) {
                if (--inDeg[next] == 0) { // minus a prerequisites from next courses
                    q.push(next);
                }
            }
        }

        return finishedCourses == numCourses;
    }
};