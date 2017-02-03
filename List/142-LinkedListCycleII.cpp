/**************************************************************************
 * File Name : 142-LinkedListCycleII.cpp
 *
 * Purpose :
 *
 * Creation Date : 02-02-2017
 *
 * Last Modified : Thu Feb  2 23:30:12 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Constant space solution
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
    ListNode *detectCycle(ListNode *head) {
        
        if(!head || !head->next) return nullptr;
        
        bool isCycled = false;
        ListNode *fast = head, *slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                isCycled = true;
                break;
            }    
        }
        
        if(!isCycled) return nullptr;
        ListNode *p = head;
        while(p!=slow){
            p = p->next;
            slow = slow->next;
        }
        
        return p;
        
    }
};


