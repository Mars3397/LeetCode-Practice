class Solution {
    static inline bool isVowel(char c) {
        c = (char)std::tolower((unsigned char)c);
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    static inline string toLower(const string& s) {
        string t; t.reserve(s.size());
        for (unsigned char ch : s) t.push_back((char)std::tolower(ch));
        return t;
    }
    static inline string devowel(const string& s) {
        string t; t.reserve(s.size());
        for (char c : s) {
            if (isVowel(c)) t.push_back('*');  // 任一固定符號皆可
            else            t.push_back((char)std::tolower((unsigned char)c));
        }
        return t;
    }
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact;
        unordered_map<string,string> lower_first;
        unordered_map<string,string> devowel_first;

        exact.reserve(wordlist.size()*2);
        lower_first.reserve(wordlist.size()*2);
        devowel_first.reserve(wordlist.size()*2);

        for (const string& w : wordlist) {
            exact.insert(w);
            string lw = toLower(w);
            if (!lower_first.count(lw)) lower_first[lw] = w;
            string vw = devowel(w);     // 先小寫再母音歸一化
            if (!devowel_first.count(vw)) devowel_first[vw] = w;
        }

        vector<string> ans; ans.reserve(queries.size());
        for (const string& q : queries) {
            if (exact.count(q)) { ans.push_back(q); continue; }

            string lq = toLower(q);
            auto it1 = lower_first.find(lq);
            if (it1 != lower_first.end()) { ans.push_back(it1->second); continue; }

            string vq = devowel(q);
            auto it2 = devowel_first.find(vq);
            if (it2 != devowel_first.end()) { ans.push_back(it2->second); continue; }

            ans.push_back("");
        }
        return ans;
    }
};
