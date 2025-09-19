/*
Approach
1. implement cache with a linked list + a hash map with list pointers
2. we store value in the linked list while store keys in the map
3. move node to head when reference

Analysis
1. time: O(1) for all operation
2. space: O(n) for linked list and map
*/


class LRUCache {
private:
    unordered_map<int, list<pair<int, int>>::iterator> key2Ptr;
    list<pair<int, int>> cache;
    int cap;

public:
    LRUCache(int capacity) {
        key2Ptr.clear();
        cache.clear();
        cap = capacity;
    }
    
    int get(int key) {
        if (!key2Ptr.count(key)) return -1;

        // update & move to head
        int val = key2Ptr[key]->second;
        cache.erase(key2Ptr[key]);
        cache.push_front({ key, val });
        key2Ptr[key] = cache.begin();

        return val;
    }
    
    void put(int key, int value) {
        if (key2Ptr.count(key)) {
            // move head
            cache.erase(key2Ptr[key]);
            cache.push_front({ key, value });
            key2Ptr[key] = cache.begin();
        } else {
            // pop the least recently used value
            if (cache.size() == cap) {
                key2Ptr.erase(cache.back().first);
                cache.pop_back();
            }

            // push to head
            cache.push_front({ key, value });
            key2Ptr[key] = cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */