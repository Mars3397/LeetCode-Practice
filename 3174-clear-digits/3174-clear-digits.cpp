/*
Approach
1. declare a new result string
2. iterate through string s to push characters into new string
3. when encounter digit pop the cloest to end non-digit char from result string

Analysis
1. O(n) < time < O(n^2)
2. space: O(1)
*/


class Solution {
public:
    string clearDigits(string s) {
        string result;

        for (char c : s) {
            if ('0' <= c && c <= '9') { // digit
                // find a non-digit to remove
                for (int i = result.size()-1; i >= 0; --i) {
                    if (result[i] < '0' || result[i] > '9') {
                        result.erase(i);
                        break;
                    }
                }
            } else {
                result.push_back(c);
            }
        }

        return result;
    }
};