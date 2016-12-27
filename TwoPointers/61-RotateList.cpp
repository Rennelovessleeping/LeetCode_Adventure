/**************************************************************************
 * File Name : 61-RotateList.cpp
 *
 * Purpose :
 *
 * Creation Date : 27-12-2016
 *
 * Last Modified : Tue Dec 27 13:56:38 2016
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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head) return head;
        int listLen = 0;
        ListNode *p = head;
        ListNode* tail = new ListNode(-1); tail->next = head;
        while(p) {
            listLen++;
            p = p->next;
            tail = tail->next;
        }
        k = listLen - k%listLen;
        if(k == listLen) return head;
        
        ListNode* newhead = head;
        p = new ListNode(-1); p->next = head;
        while(k>0){
            p = p->next;
            newhead = newhead->next;
            k--;
        }
        p->next = NULL;
        tail->next = head;
        
        return newhead;
    }
};


// Connect the list
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        //---- test case----//
        /*
        k = 2;
        head = new ListNode(1);
        ListNode *ptr = head;
        ptr->next = new ListNode(2); ptr = ptr->next;
        ptr->next = new ListNode(3); ptr = ptr->next;
        ptr->next = new ListNode(4); ptr = ptr->next;
        ptr->next = new ListNode(4);
        */
        
        if(!head) return head;
        int listLen = 1;
        ListNode *newhead = head;
        ListNode* tail = head;
        while(tail->next) {
            listLen++;
            tail = tail->next;
        }

        tail->next = head; // connect the list
        
        if( k%=listLen){
            for(int i;i<listLen-k;i++) {
                newhead=newhead->next; 
                tail=tail->next;
            }
        }
        
        tail->next = NULL;
        return newhead;
    }
};

