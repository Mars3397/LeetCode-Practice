/*
Approach
1. store the intevals in head2tail and tail2head
2. merge overlapping intervals when insert new numbers
3. record the maximum sequence while inserting

Analysis
1. time: O(n)
2. space: O(n)
*/


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> head2tail, tail2head;
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLen = 0;

        for (int num : numSet) {
            auto front = tail2head.find(num-1);
            auto back = head2tail.find(num+1);

            if (front != tail2head.end() && back != head2tail.end()) {
                head2tail[front->second] = back->second;
                tail2head[back->second] = front->second;
                maxLen = max(maxLen, back->second - front->second + 1);
                tail2head.erase(front);
                head2tail.erase(back);
            } else if (front != tail2head.end()) {
                head2tail[front->second] = num;
                tail2head[num] = front->second;
                maxLen = max(maxLen, num - front->second + 1);
                tail2head.erase(num-1);
            } else if (back != head2tail.end()) {
                tail2head[back->second] = num;
                head2tail[num] = back->second;
                maxLen = max(maxLen, back->second - num + 1);
                head2tail.erase(num+1);
            } else {
                head2tail[num] = num;
                tail2head[num] = num;
                maxLen = max(maxLen, 1);
            }
        }

        return maxLen;
    }
};