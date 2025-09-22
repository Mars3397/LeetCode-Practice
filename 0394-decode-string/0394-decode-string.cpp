/*
Approach
1. use a recursive approach to match k and following string
2. call the recursive function when encounter '[' to decode inner string
3. return the decoded string and append to result in the upper level

Analysis
1. time: 
2. space: 
*/


class Solution {
private:
    int N;

    string decode(string &s, int &i) {
        string result;
        int k = 0;
        
        while (i < N && s[i] != ']') {
            if (isdigit(s[i])) {
                k = k * 10 + (s[i] - '0');
            } else if (s[i] == '[') {
                ++i; // skip [
                string inner = decode(s, i);
                for (int i = 0; i < k; ++i) {
                    result += inner;
                }
                k = 0;
            } else {
                result.push_back(s[i]);
            }

            ++i;
        }

        return result;
    }

public:
    string decodeString(string s) {
        N = s.size();
        int i = 0;

        return decode(s, i);
    }
};