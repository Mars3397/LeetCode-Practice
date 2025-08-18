/*
Approach 
1. declare an unordered_map to store the mapping of pointers from old to new
2. use DFS to iterate through graph to clone

Analysis
1. time: O(n) where n = number of nodes in the graph
2. space: O(n) where n = number of nodes in the graph
*/

class Solution {
private:
    unordered_map<Node*, Node*> old2new;

    void clone(Node* n) {
        auto newNode = old2new.find(n);

        for (Node* nei : n->neighbors) {
            if (!old2new.count(nei)) {
                old2new[nei] = new Node(nei->val);
                newNode->second->neighbors.push_back(old2new[nei]);
                clone(nei);
            } else {
                newNode->second->neighbors.push_back(old2new[nei]);
            }
        }
    }

public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // init
        old2new[node] = new Node(node->val);

        // clone whole graph
        clone(node);

        return old2new[node];
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/