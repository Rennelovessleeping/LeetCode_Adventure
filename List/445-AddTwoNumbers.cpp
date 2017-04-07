/**************************************************************************
 * File Name : 445-AddTwoNumbers.cpp
 *
 * Purpose :
 *
 * Creation Date : 07-04-2017
 *
 * Last Modified : Fri Apr  7 14:58:36 2017
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
        
        stack<int> num1, num2;
        while(l1) {
            num1.push(l1->val);
            l1 = l1->next;
        }
        while(l2) {
            num2.push(l2->val);
            l2 = l2->next;
        }
        
        int carry = 0;
        ListNode *head = new ListNode(0);
        while(!num1.empty() || !num2.empty() || carry) {
            if(!num1.empty()) {
                carry += num1.top();
                num1.pop();
            }
            if(!num2.empty()) {
                carry += num2.top();
                num2.pop();
            }
            head->val = carry%10;
            ListNode *p = new ListNode(0);
            p->next = head;
            head = p;
            carry /= 10;
        }
        
        return head->next;
        
    }
};
