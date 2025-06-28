class Trie {
private:
    struct TrieNode {
        bool endHere;
        vector<TrieNode*> nodes;

        TrieNode() {
            endHere = false;
            nodes = vector<TrieNode*> (26);
        }
    };

    TrieNode* treeHead;

public:
    Trie() {
        treeHead = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = treeHead;
        for (char c : word) {
            if (!cur->nodes[c-'a']) {
                cur->nodes[c-'a'] = new TrieNode();
            }

            cur = cur->nodes[c-'a'];
        }

        cur->endHere = true;
    }
    
    bool search(string word) {
        TrieNode* cur = treeHead;
        for (char c : word) {
            if (!cur->nodes[c-'a']) {
                return false;
            }

            cur = cur->nodes[c-'a'];
        }

        return cur->endHere;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = treeHead;
        for (char c : prefix) {
            if (!cur->nodes[c-'a']) {
                return false;
            }

            cur = cur->nodes[c-'a'];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */