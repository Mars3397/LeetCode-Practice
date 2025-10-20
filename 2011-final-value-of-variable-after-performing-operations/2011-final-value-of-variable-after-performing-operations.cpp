class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int final = 0;

        for (string &s : operations) {
            if (s == "++X" || s == "X++") {
                ++final;
            } else {
                --final;
            }
        }

        return final;
    }
};