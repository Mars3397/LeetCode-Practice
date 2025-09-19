/*
Approach
1. single pass
2. point the prev node to the next of deleted node

Analysis
1. time: O(n) where n = the length of linked list
2. space: O(1)
*/


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return nullptr; // length = 0

        // declare dummy node
        ListNode dummy = ListNode();
        dummy.next = head;

        // declare pointers
        ListNode *prev = &dummy, *cur = head;

        // iterate through linked list
        while (cur) {
            if (cur->val == val) {
                prev->next = cur->next; // delete target node
                cur = cur->next;
            } else {
                prev = prev->next;
                cur = cur->next;
            }
        }

        return dummy.next;
    }
};