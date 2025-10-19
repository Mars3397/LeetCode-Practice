/*
1 true
2 true
3 true
4 false
5 true
6 true
7 true
8 false
9 

*/


class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};

