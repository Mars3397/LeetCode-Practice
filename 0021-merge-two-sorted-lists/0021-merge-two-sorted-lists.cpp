/*
Approach
1. declare a dummy node to link the head of the new list
2. declare a pointer points to dummy node
3. repeatly to link the smaller one to new list until list1 and list2 are nullptr

Analysis
1. time: O(m+n) where m = the length of list1 and n = the length of list2
2. space: O(1)
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy = ListNode();
        ListNode* cur = &dummy;

        while (list1 || list2) {
            if (!list1) {
                cur->next = list2;
                list2 = list2->next;
            } else if (!list2) {
                cur->next = list1;
                list1 = list1->next;
            } else if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }

            cur = cur->next;
        }

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