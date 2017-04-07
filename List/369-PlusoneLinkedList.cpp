/**************************************************************************
 * File Name : 369-PlusoneLinkedList.cpp
 *
 * Purpose :
 *
 * Creation Date : 07-04-2017
 *
 * Last Modified : Fri Apr  7 14:43:20 2017
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
    ListNode* plusOne(ListNode* head) {
        int carry = helper(head);
        if(carry == 0) return head;
        ListNode *p = new ListNode(1);
        p->next = head;
        return p;
    }
    
    int helper(ListNode* head) {
        if(!head->next) {
            int tmp = head->val + 1;
            head->val = tmp%10;
            return tmp/10;
        }
        
        int carry = helper(head->next);
        int tmp = carry + head->val;
        head->val = tmp%10;
        return tmp/10;
    }
};
