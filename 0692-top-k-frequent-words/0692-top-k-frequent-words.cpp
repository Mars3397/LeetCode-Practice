/*
Approach
1. calculate the frequency of each words in an unordered_map
2. push them to a priority queue (min-heap to pop least frequet element) with size k
3. return the remaining string in the queue

Analsis
1. time: O(n) + O(nlogk) + O(n) = O(nlogk)
2. space: O(n) + O(k) + O(n) = O(n)
*/


class Solution {
private:
    // sort the pairs with frequency from low to high and in reverse lexicographical order
    struct PairCompare {
        bool operator()(pair<int, string> &a, pair<int, string> &b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        }
    };

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;

        // record the freq of wach word
        for (const string &w : words) {
            ++freq[w];
        }

        // push (freq, word) to a priority queue with size k
        priority_queue<pair<int, string>, vector<pair<int, string>>, PairCompare> pq;
        for (auto &[w, f] : freq) {
            pq.push({ f, w });

            // maintain the size of pq (pop out the least frequent element)
            if (pq.size() > k) pq.pop();
        }

        // push to result vector (currently is from low frequency to high because using min-heap)
        vector<string> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        // reverse to make the freq is from high to low
        reverse(result.begin(), result.end());

        return result;
    }
};