/*
Approach
1. use a nested map to implement TimeMap where the key of first map is key and the second one is timestamp
2. use lower_bound to find the largest timestamp smaller than given one when not exist

Analysis
1. 
*/

class TimeMap {
private:
    unordered_map<string, map<int, string>> timeMap;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        if (timeMap.count(key)) {
            timeMap[key][timestamp] = value;
        } else {
            timeMap[key] = {{timestamp, value}};
        }
    }
    
    string get(string key, int timestamp) {
        if (timeMap.count(key)) {
            if (timeMap[key].count(timestamp)) {
                return timeMap[key][timestamp];
            } else {
                auto it = timeMap[key].lower_bound(timestamp);
                if (it != timeMap[key].begin()) {
                    return (--it)->second;
                }
            }
        }

        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */