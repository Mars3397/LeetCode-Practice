/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }                  
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> old2new;
        Node dummy = Node(0);
        Node *cur = &dummy, *copy = head;

        while (head) {
            if (!old2new.count(head)) {
                old2new[head] = new Node(head->val);
            }

            if (head->random && !old2new.count(head->random)) {
                old2new[head->random] = new Node(head->random->val);
            }

            old2new[head]->random = old2new[head->random];
            cur->next = old2new[head];
            cur = cur->next;
            head = head->next;
        }

        return old2new[copy];
    }
};