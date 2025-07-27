/*
Approach
1. implement LRU cache using linked list + hash table
2. move the used list node to the end of list
3. remove the head of list when full

Analysis
1. time: O(1) for all operations
2. space: O(n) where n = total number of stored keys
*/


class LRUCache {
private:
    struct ListNode {
        int key;
        int val;
        ListNode *child;
        ListNode *parent;

        ListNode(int k, int v) {
            key = k;
            val = v;
            child = nullptr;
            parent = nullptr;
        }
    };

    ListNode *listEnd;
    ListNode *listHead;
    int cap;
    unordered_map<int, ListNode*> umap;

    void moveToEnd(ListNode *n) {
        if (!listEnd) {
            listEnd = n;
            listHead = n;
            return;
        }

        listEnd->child = n;
        n->parent = listEnd;
        listEnd = n;
    }

    void cutFromList(ListNode *n) {
        if (!n->parent) {
            listHead = n->child;
        } else {
            n->parent->child = n->child;
        }

        if (!n->child) {
            listEnd = n->parent;
        } else {
            n->child->parent = n->parent;
        }

        n->parent = nullptr;
        n->child = nullptr;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        listEnd = nullptr;
        listHead = nullptr;
    }
    
    int get(int key) {
        auto f = umap.find(key);
        if (f == umap.end()) return -1;

        cutFromList(f->second);
        moveToEnd(f->second);

        return f->second->val;
    }
    
    void put(int key, int value) {
        ListNode *node;
        if (umap.count(key)) {
            node = umap[key];
            node->val = value;
            cutFromList(node);
        } else {
            node = new ListNode(key, value);
            umap[key] = node;
        }

        moveToEnd(node);

        if (umap.size() > cap) {
            umap.erase(listHead->key);
            listHead->child->parent = nullptr;
            listHead = listHead->child;
        }
    }
};
