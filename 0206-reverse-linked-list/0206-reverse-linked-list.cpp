/*
Approach 
1. use 3 pointers to perform reverse: prev, cur, next
2. in every iteration: point cur->next to prev, and move all 1 step ahead

Analysis
1. time: O(n) where n = number of nodes in the list
2. space: O(1)
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // no operation needed to reverse a list with length 0 or 1 
        if (!head || !head->next) return head;

        ListNode *prev = nullptr, *cur = head;

        while (cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
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