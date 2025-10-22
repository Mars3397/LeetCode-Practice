class Solution {
public:
    int strStr(string haystack, string needle) {
        auto f = haystack.find(needle);
        return f == string::npos ? -1 : f;
    }
};