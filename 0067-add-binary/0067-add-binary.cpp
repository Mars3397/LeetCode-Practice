class Solution {
private: 
    string add(string &large, string &small) {
        int l = static_cast<int>(large.size()) - 1;
        int s = static_cast<int>(small.size()) - 1;
        bool carry = false;

        while (s >= 0) {
            large[l] += carry + (small[s] - '0');

            if (large[l] >= '2') {
                large[l] -= 2;
                carry = true;
            } else {
                carry = false;
            }

            --l; --s;
        }

        while (l >= 0) {
            large[l] += carry;

            if (large[l] >= '2') {
                large[l] -= 2;
                carry = true;
            } else {
                return large;
            }

            --l;
        }

        return "1" + large;
    }

public:
    string addBinary(string a, string b) {
        if (a == "0" && b == "0") return "0";
        if (a == "0") return b;
        if (b == "0") return a;

        if (a.size() > b.size()) return add(a, b);
        
        return add(b, a);
    }
};