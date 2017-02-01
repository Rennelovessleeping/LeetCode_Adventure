/**************************************************************************
 * File Name : 92-ReversedLinkedListII.cpp
 *
 * Purpose :
 *
 * Creation Date : 01-02-2017
 *
 * Last Modified : Wed Feb  1 00:30:52 2017
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *bp=head, *ep=head;
        ListNode *newhead = new ListNode(-1), *tail = newhead;
        newhead->next = head;
        
        while(m>1) {bp = bp->next; tail = tail->next; m--;}
        while(n>1) {ep = ep->next; n--;}
        
        tail->next = helper(bp, ep);
        return newhead->next;
    }
    
    ListNode* helper(ListNode* bp, ListNode* ep){
        ListNode *ptr, *ending = ep->next;
        ListNode *node = new ListNode(-1);
        node->next = ending;
        while(bp!=ending){
            cout << bp->val << endl;
            ptr = bp->next;
            bp->next = node->next;
            node->next = bp;
            bp = ptr;
        }
        
        return node->next;
    }
};
