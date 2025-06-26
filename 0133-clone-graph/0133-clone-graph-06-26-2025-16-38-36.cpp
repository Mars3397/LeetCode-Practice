/*
Approach
1. iteratively to construct the cloned graph
2. declare a hash table to map nodes

Analysis
1. time: O(n) where n = number of nodes in the graph
2. space: O(n) where n = number of nodes in the graph
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        Node *newHead = new Node(node->val);
        unordered_map<Node*, Node*> nodeMapping;
        nodeMapping[node] = newHead;

        // use to traverse original graph
        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node *n = q.front(); q.pop();

            int nb = n->neighbors.size();
            for (int i = 0; i < nb; i++) {
                Node *newNode;
                if (nodeMapping.count(n->neighbors[i])) {
                    newNode = nodeMapping[n->neighbors[i]];
                } else {
                    newNode = new Node(n->neighbors[i]->val);
                    nodeMapping[n->neighbors[i]] = newNode;
                    q.push(n->neighbors[i]); // only explore new node
                }
                nodeMapping[n]->neighbors.push_back(newNode);
            }
        }

        return newHead;
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