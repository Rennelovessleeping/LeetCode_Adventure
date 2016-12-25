/**************************************************************************
 * File Name : 237-DeleteNodeInLinkedList.cpp
 *
 * Purpose :
 *
 * Creation Date : 25-12-2016
 *
 * Last Modified : Sun Dec 25 12:58:17 2016
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
    void deleteNode(ListNode* node) {
        
        while(node->next->next){ // When the next node is not the end
            node->val = node->next->val;
            node = node->next;
        }
        
        node->val = node->next->val; // copy the end node;
        delete node->next;
        node->next = NULL;
        
    }
};
