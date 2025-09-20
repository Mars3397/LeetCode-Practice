class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        result.reserve(n);

        if (n % 2 == 1) {
            result.push_back(0);
            n -= 1;
        }

        for (int i = 0; i < n; i+=2) {
            result.push_back(i+1);
            result.push_back(-(i+1));
        }

        return result;
    }
};