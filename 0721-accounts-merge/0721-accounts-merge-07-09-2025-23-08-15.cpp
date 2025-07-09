class Solution {
private:
    unordered_map<string, string> parent;

    string find(string x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailToName;

        // Step 1: Union
        for (auto &acc : accounts) {
            string name = acc[0];
            for (int i = 1; i < acc.size(); ++i) {
                parent[acc[i]] = acc[i]; // every account's initial root is them self
                emailToName[acc[i]] = name;
            }
        }

        for (auto &acc : accounts) {
            string rootEmail = acc[1]; // choose the first email to be representitive email
            for (int i = 2; i < acc.size(); ++i) {
                parent[find(acc[i])] = find(rootEmail); // union
            }
        }

        // Step 2: group emails by root
        unordered_map<string, vector<string>> groups;
        for (auto &[email, _] : emailToName) {
            string root = find(email);
            groups[root].push_back(email);
        }

        // Step 3: format output
        vector<vector<string>> res;
        for (auto &[root, emails] : groups) {
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), emailToName[root]);
            res.push_back(emails);
        }

        return res;
    }
};
