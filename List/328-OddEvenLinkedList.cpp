/**************************************************************************
 * File Name : 328-OddEvenLinkedList.cpp
 *
 * Purpose :
 *
 * Creation Date : 03-02-2017
 *
 * Last Modified : Fri Feb  3 22:45:21 2017
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        int i = 1;
        ListNode odd(-1), even(-1);
        ListNode *po = &odd, *pe = &even; 
        while(head){
            if (i%2 != 0) po = po->next = head;
            else pe = pe->next = head;
            head = head->next;
            i++;
        }
        
        pe->next = nullptr;
        po->next = even.next;
        
        return odd.next;
        
    }
};
