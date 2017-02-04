/**************************************************************************
 * File Name : 143-ReorderList.cpp
 *
 * Purpose :
 *
 * Creation Date : 03-02-2017
 *
 * Last Modified : Fri Feb  3 23:15:21 2017
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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *newtail = new ListNode(-1);
        newtail->next = head;
        ListNode *p = head;
        while(p->next) {
            p=p->next;
            newtail = newtail->next;
        }
        if(newtail == head) return;
        
        p->next = head->next;
        head->next = p;
        newtail->next = NULL;
        
        reorderList(p->next);

    }

};

// Split the linked list, reverse the back half and ther merge the two list;
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *slow = head , *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *back = slow->next;
        slow->next = nullptr;
        
        // Reverse the back half list:
        ListNode *toAdd = back->next;
        back->next = nullptr;
        
        while(toAdd){
            fast = toAdd->next;
            toAdd->next = back;
            back = toAdd;
            toAdd = fast;
        }
        
        // Merge two list:
        slow = head;
        while(slow) {
            auto tmp = slow->next;
            slow = slow->next = back;
            back = tmp;
        }

    }

};
