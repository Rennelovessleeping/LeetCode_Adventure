/**************************************************************************
 * File Name : 82-RemoveDuplicatesFromLinkedList.cpp
 *
 * Purpose :
 *
 * Creation Date : 02-02-2017
 *
 * Last Modified : Thu Feb  2 19:52:18 2017
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        ListNode *newhead = new ListNode(-1); newhead->next = head;
        ListNode *tail = newhead;
        
        while(head && head->next){
            if(head->val == head->next->val){
                tail->next = remover(head, head->val);
                head = tail->next;
            }
            else{
                head = head->next;
                tail = tail->next;
            }
        }
        return newhead->next;
        
    }
    
private:
    ListNode* remover(ListNode* head, int value){
        if(!head) return nullptr;
        head->next = remover(head->next, value);
        return head->val == value ? head->next : head;
    }
};

// Recursive solution
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head || !head->next) return head;
        int value = head->val;
        ListNode *p = head->next;
        
        if(p->val !=value){
            head->next = deleteDuplicates(head->next);
            return head;
        }
        else{
            while(p && p->val == value) p = p->next; // Move p to next non-repeating elements
            return deleteDuplicates(p);
        }
        
    }
};


