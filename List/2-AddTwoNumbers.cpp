/**************************************************************************
 * File Name : 2-AddTwoNumbers.cpp
 *
 * Purpose :
 *
 * Creation Date : 02-01-2017
 *
 * Last Modified : Mon Jan  2 14:30:26 2017
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(!l1 || !l2) return l1==NULL ? l2:l1;
        
        ListNode* head = l2;
        
        while(l1->next && l2->next){
            l2->val += l1->val;
            l1 = l1->next;
            l2 = l2->next;
        }
        l2->val += l1->val;
        if(!l2->next) l2->next = l1->next;
        
        l2 = head;
        int carry = 0;
        while(l2->next) {
            l2->val += carry;
            if(l2->val>=10){
                l2->val %= 10;
                carry = 1;
            }
            else carry = 0;
            
            l2 = l2->next;
        }
        // Post-treatment on the last node
        l2->val += carry;
        if(l2->val>=10){
            l2->val %= 10;
            l2->next = new ListNode(1);
        }
        
        return head;
    }

};

// More concise solution
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode head(-1), *p=&head;
        int carry = 0, sum;
        
        while(l1 || l2 || carry){
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val:0) + carry;
            carry = sum/10;
            p->next = new ListNode(sum%10);
            p = p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        
        
        return head.next;
        
    }

};
