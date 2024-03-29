/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 

Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000 */

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
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *curr, *prev, *next, *left, *right;
        int len = 0;
        int count = 0;
        
        curr = head;
        while (curr != NULL) {
            curr = curr->next;
            len++;
        }
        
        curr = head;
        while (count < (len/2)) {
            curr = curr->next;
            count++;
        }
        
        //Reverse 2nd half of list
        prev = curr;
        curr = curr->next;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // Two pointers progressing in opp. directions
        left = head;
        right = prev;
        count = 0;
        while (count < (len/2)) {
            next = left->next;
            prev = right->next;
            left->next = right;
            right->next = next;
            left = next;
            right = prev;
            count++;
        }
        left->next = NULL;
    }
};
