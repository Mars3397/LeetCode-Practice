/*
Approach
1. use a priority queue to store stones
2. pop first 2 stone and smash -> then push the remain back
3. repeat step 2 until size of pq become 1
4. return the remain stone

Analysis
1. time: O(n) where n = stones.size()
2. space: O(n) where n = stones.size()
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while (pq.size() > 1) {
            int stone1 = pq.top(); pq.pop();
            int stone2 = pq.top(); pq.pop();
            
            int left = stone1 - stone2;
            if (left > 0) {
                pq.push(left);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};