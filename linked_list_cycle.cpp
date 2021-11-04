/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.*/

// Comment -> Use two pointers, both traversing the list at different rates. Think of two people going around in a circle ar different speeds, they have to meet at some point.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *curr1, *curr2;
        
        if (head == NULL) {
            return false;
        }
        
        curr1 = head;
        curr2 = head->next;
        
        while (curr1 != NULL && curr2 != NULL && curr2->next != NULL) {
            if (curr1 == curr2) {
                return true;
            }
            curr1 = curr1->next;
            curr2 = curr2->next->next;
        }
        
        return false;
    }
};
