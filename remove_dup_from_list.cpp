/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr, *prev;
        
        if (head == NULL) {
            return NULL;
        }
        
        prev = head;
        curr = head->next;
        
        while (curr != NULL) {
            if (curr->val == prev->val) {
                prev->next = curr->next;
            }
            else {
                prev = curr;
            }
            curr = curr->next;
        }
        
        return head;
    }
}; 
