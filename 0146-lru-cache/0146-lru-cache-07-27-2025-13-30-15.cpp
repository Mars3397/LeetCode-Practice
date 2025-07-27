/*
Approach
1. implement LRU cache using linked list + hash table
2. move the used list node to the end of list
3. remove the head of list when full

Analysis
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

    void printList(ListNode* head) {
        ListNode* cur = head;

        while (cur) {
            cout << "(" << cur->key;
            cout << ", " << cur->val;
            cout << ") -> ";

            cur = cur->child;
        }

        cout << endl;
    }

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
        if (!umap.count(key)) return -1;
        ListNode* f = umap[key];

        cutFromList(f);
        moveToEnd(f);

        return f->val;
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

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */