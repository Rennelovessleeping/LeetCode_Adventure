/**************************************************************************
 * File Name : 206-ReverseLinkedList.cpp
 *
 * Purpose :
 *
 * Creation Date : 31-01-2017
 *
 * Last Modified : Tue Jan 31 23:42:30 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Iterative solution
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
    ListNode* reverseList(ListNode* head) {
        ListNode* newhead = new ListNode(-1);
        ListNode* ptr;
        while(head){
            ptr = head->next;
            head->next = newhead->next;
            newhead->next = head;
            head = ptr;
        }
        head = newhead->next;
        delete newhead;
        return head;
    }
};

// Recursive solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode * newhead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
};
