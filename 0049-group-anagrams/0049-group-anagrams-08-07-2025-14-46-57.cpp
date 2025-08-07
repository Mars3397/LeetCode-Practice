/*
Approach
1. compute the frequency of characters for each string and form a unique key for the anagram
2. concate the frequency to a string to form a key
3. store each anagram group in an unordered map

Analysis
1. time: O(n * m) where n = strs.size() and m = average of the length of string in strs
2. space: O(n * m) where n = strs.size() and m = average of the length of string in strs
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (string &str : strs) {
            // count frequency
            vector<int> freq(26, 0);
            for (char c : str) {
                ++freq[c - 'a'];
            }

            // form key
            string key = "";
            for (int i = 0; i < 26; ++i) {
                key += to_string(freq[i]) + "#";
            }

            groups[key].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto [key, val] : groups) {
            ans.push_back(val);
        }

        return ans;
    }
};