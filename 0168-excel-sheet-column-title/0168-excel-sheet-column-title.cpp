class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";

        while (columnNumber > 0) {
            int remain = columnNumber % 26;

            if (remain == 0) {
                result.push_back('Z');
                columnNumber = (columnNumber - 1) / 26;
            } else {
                result.push_back(remain - 1 + 'A');
                columnNumber /= 26;
            }
        }

        reverse(result.begin(), result.end());

        return result;
    }
};