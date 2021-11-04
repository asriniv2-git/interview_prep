/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

The test cases are generated such that there are no cycles anywhere in the entire linked structure.

Note that the linked lists must retain their original structure after the function returns.*/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = 0;
        int lengthB = 0;
        int len = 0;
        ListNode *currA, *currB;
        
        currA = headA;
        while (currA != NULL) {
            lengthA++;
            currA = currA->next;
        }
        
        currB = headB;
        while (currB != NULL) {
            lengthB++;
            currB = currB->next;
        }
        
        currA = headA;
        currB = headB;
        if (lengthA > lengthB) {
            while (len < (lengthA - lengthB)) {
                len++;
                currA = currA->next;
            }
        }
        else {
            while (len < (lengthB - lengthA)) {
                len++;
                currB = currB->next;
            }
        }
        
        while (currA != NULL) {
            if (currA == currB) {
                return currA;
            }
            currA = currA->next;
            currB = currB->next;
        }
        
        return NULL;
    }
};
