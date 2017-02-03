/**************************************************************************
 * File Name : 83-RemoveDuplicatesFromLinkedList.cpp
 *
 * Purpose :
 *
 * Creation Date : 02-02-2017
 *
 * Last Modified : Thu Feb  2 19:08:40 2017
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
        
        ListNode *node = head;
        while(node && node->next){
            while(node->next && node->val == node->next->val){
                node->next = node->next->next;
            }
            node = node->next;
        }
        return head;
    }
};

