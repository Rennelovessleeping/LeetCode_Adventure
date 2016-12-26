/**************************************************************************
 * File Name : 234-PalindromeLinkedList.cpp
 *
 * Purpose :
 *
 * Creation Date : 26-12-2016
 *
 * Last Modified : Mon Dec 26 16:12:42 2016
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
    bool isPalindrome(ListNode* head) {
        
        if(!head || !head->next) return true; // Case of 0 or 1 node;
       
        ListNode *slow=head, *fast=head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next ;
        }
        
        slow = slow->next;
        if(slow == fast->next) return slow->val == fast->val;
        
        vector<int> slicedList;
        while(slow){
            slicedList.push_back(slow->val);
            slow = slow->next;
        }
        
        for(int i=slicedList.size()-1;i>=0;i--){
            if(head->val != slicedList[i]) return false;
            head = head->next;
        }
        
        return true;
        
    }
};
