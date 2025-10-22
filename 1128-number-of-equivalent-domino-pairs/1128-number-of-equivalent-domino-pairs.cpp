class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> freq;

        int n = dominoes.size(), cnt = 0;
        for (int i = 0; i < n; ++i) {
            int target1 = dominoes[i][0] * 10 + dominoes[i][1];
            int target2 = dominoes[i][1] * 10 + dominoes[i][0];

            auto f1 = freq.find(target1);
            if (f1 != freq.end()) cnt += f1->second;

            ++freq[target1];

            if (target1 == target2) continue;

            auto f2 = freq.find(target2);
            if (f2 != freq.end()) cnt += f2->second;
        }

        return cnt;
    }
};