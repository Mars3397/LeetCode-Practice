class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        vector<int> v(n1 + n2);

        for (int i = n1-1; i >= 0; --i) {
            for (int j = n2-1; j >= 0; --j) {
                int idx = (n1 - 1 - i) + (n2 - 1 - j);

                v[idx] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        int carry = 0;
        for (int i = 0; i < v.size(); ++i) {
            v[i] += carry;
            carry = v[i] / 10;
            v[i] %= 10;
        }

        string result = "";
        bool leadingZero = true;
        for (int i = v.size()-1; i >= 0; --i) {
            if (leadingZero && v[i] == 0) continue;
            else leadingZero = false;
            
            result.push_back(v[i] + '0');
        }

        return result == "" ? "0" : result;
    }
};