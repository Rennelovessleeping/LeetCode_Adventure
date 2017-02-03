/**************************************************************************
 * File Name : 203-RemoveLinkedListElements.cpp
 *
 * Purpose :
 *
 * Creation Date : 02-02-2017
 *
 * Last Modified : Thu Feb  2 19:45:49 2017
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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode *newhead = new ListNode(-1);
        newhead->next = head;
        ListNode *back = newhead;
        
        while(head){
            if(head->val == val){
                back->next = head->next;
                head = back->next;
            }
            else{
                head = head->next;
                back = back->next;
            }
            
        }
        
        return newhead->next;
    }
};

// Recursive solution
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};

