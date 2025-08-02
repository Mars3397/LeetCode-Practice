/*
Approach
1. use three pointers to solve in one pass
2. first move "end" pointer n nodes ahead
3. move "end", "cur", "prev" at the same time until end == nullptr
4. remove cur nodes

Analysis
1. time: O(m) where m = number of nodes in the list
2. space: O(1)
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // declare a dummy head
        ListNode dummy = ListNode();
        dummy.next = head;

        // declare pointers
        ListNode *prev = &dummy, *cur = head, *end = head;

        // move end pointer n steps ahead
        for (int i = 0; i < n; ++i) {
            end = end->next;
        }

        // move 3 pointers together until end == nullptr
        while (end) {
            end = end->next;
            cur = cur->next;
            prev = prev->next;
        }

        // remove node at cur
        prev->next = cur->next;

        return dummy.next;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */