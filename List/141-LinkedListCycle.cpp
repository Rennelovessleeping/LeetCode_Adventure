/**************************************************************************
 * File Name : 141-LinkedListCycle.cpp
 *
 * Purpose :
 *
 * Creation Date : 23-12-2016
 *
 * Last Modified : Fri Dec 23 16:54:07 2016
 *
 * Created By :  Renne Bai
**************************************************************************/
// Use unordered set. But this methods demands extra space.
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
    bool hasCycle(ListNode *head) {
        
        unordered_set<ListNode*> s;
        
        while(head){
            if(!s.insert(head).second) return true;
            head = head->next;
        }
        
        return false;
    }
};


// Loopthrough cycle.
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(head == NULL) return false; // Null List.
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) return true;
        }
        
        return false;
    }
};





