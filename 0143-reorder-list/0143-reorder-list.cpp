/*
Approach
1. divide the list into first half and second half
2. revert the second half
3. sew these 2 half

Analysis
1. time: O(n) where n = number of nodes in the list
2. space: O(1)
*/

class Solution {
private:
    ListNode* reverseList(ListNode *head) {
        ListNode *prev = nullptr, *cur = head, *next = nullptr;

        while (cur) {
            // store
            next = cur->next;

            // reverse
            cur->next = prev;

            // move to next
            prev = cur;
            cur = next;
        }

        return prev;
    }

public:
    void reorderList(ListNode* head) {
        // step 1. divide the list
        ListNode *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // step 2. revert the second one
        ListNode *second = slow->next;
        slow->next = nullptr;

        ListNode *head1 = head;
        ListNode *head2 = reverseList(second);

        // step 3. sew 2 linked lists
        while (head1 && head2) {
            ListNode *next1 = head1->next;
            ListNode *next2 = head2->next;

            head1->next = head2;
            head2->next = next1;

            head1 = next1;
            head2 = next2;
        }
    }
};