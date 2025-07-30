/*
Apporoach
1. record the carry in a boolean value
2. add values from list2 to list1 and return the list1 head


*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1, *last = nullptr;
        bool carry = false;

        // add up same length digits
        while (l1 || l2 || carry) {
            if (l1 && l2) {
                l1->val += l2->val + carry;
                if (l1->val >= 10) {
                    l1->val -= 10;
                    carry = true;
                } else {
                    carry = false;
                }
                last = l1;
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1) {
                l1->val += carry;
                if (l1->val >= 10) {
                    l1->val -= 10;
                    carry = true;
                } else {
                    carry = false;
                }
                last = l1;
                l1 = l1->next;
            } else if (l2) {
                last->next = l2;
                l2->val += carry;
                if (l2->val >= 10) {
                    l2->val -= 10;
                    carry = true;
                } else {
                    carry = false;
                }
                last = last->next;
                l2 = l2->next;
            } else if (carry) {
                last->next = new ListNode(1);
                carry = false;
            }
        }

        return head;
    }
};