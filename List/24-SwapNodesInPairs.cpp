/**************************************************************************
 * File Name : 24-SwapNodesInPairs.cpp
 *
 * Purpose :
 *
 * Creation Date : 01-02-2017
 *
 * Last Modified : Wed Feb  1 21:38:30 2017
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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *newhead = new ListNode(-1);
        newhead->next = head;
        ListNode *left = head, *right = head->next, *tail=newhead;
        
        while(right){
            ListNode *nextLeft, *nextRight;
            nextLeft = left->next->next;
            nextRight = right->next ? right->next->next : right->next;
            // swap
            tail->next = right;
            left->next = right->next;
            right->next = left;
            
            tail = tail->next->next;
            left = nextLeft;
            right = nextRight;
        }
        
        return newhead->next;
    }
};

// Concise solution:
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode **tail = &head, *left, *right; 
        while((left = *tail) && (right=left->next)){
            left->next = right->next;
            right->next = left;
            *tail = right;
            tail = &(left->next);
        }
        return head;
    }
};
