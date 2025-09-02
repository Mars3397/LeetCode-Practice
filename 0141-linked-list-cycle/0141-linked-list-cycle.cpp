/*
Approach
1. use fast and slow pointers to detect linked list cycle

Analysis
1. time: O(n) where n = number of nodes in the list
2. space: O(1)
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;

        ListNode *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) return true;
        }

        return false;
    }
};