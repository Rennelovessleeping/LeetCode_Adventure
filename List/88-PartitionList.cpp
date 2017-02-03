/**************************************************************************
 * File Name : 88-PartitionList.cpp
 *
 * Purpose :
 *
 * Creation Date : 02-02-2017
 *
 * Last Modified : Thu Feb  2 20:20:10 2017
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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode less(-1), larger(-1);
        ListNode *left = &less, *right = &larger;
        
        while(head){
            if(head->val < x) left = left->next = head;
            else right = right->next = head; // Not able to assign the last nullptr in while loop
            head = head->next;
        }
        left->next = larger.next; 
        right->next = NULL;
        return less.next;
    }
};
