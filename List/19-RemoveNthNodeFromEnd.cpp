/**************************************************************************
 * File Name : 19-RemoveNthNodeFromEnd.cpp
 *
 * Purpose :
 *
 * Creation Date : 24-12-2016
 *
 * Last Modified : Sat Dec 24 01:01:18 2016
 *
 * Created By :  Renne Bai
**************************************************************************/
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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int len=0;
        ListNode* leader = head;
        ListNode newHead(-1); // Avoid the special case of list with single element;
        newHead.next = head;
        ListNode* trailor = &newHead;
        
        while(leader){
            leader = leader->next;
            len++;
            if(len >n) trailor = trailor->next;
        }
        
        if(trailor->next) {
            ListNode* to_be_deleted = trailor->next;
            trailor->next = trailor->next->next;
            delete to_be_deleted; // Free the memory;
        }
        return newHead.next;
        
    }
};



