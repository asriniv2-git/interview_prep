/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *tail, *head;
        
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        
        if (l1->val < l2->val) {
            head = new ListNode(l1->val);
            l1 = l1->next;
        }
        else {
            head = new ListNode(l2->val);
            l2 = l2->next;
        }
        tail = head;
        
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                tail->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else {
                tail->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        if (l1 != NULL) {
            tail->next = l1;
        }
        else {
            tail->next = l2;
        }
        
        return head;
    }
};
