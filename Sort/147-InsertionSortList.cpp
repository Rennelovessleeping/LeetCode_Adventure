/**************************************************************************
 * File Name : 147-InsertionSortList.cpp
 *
 * Purpose :
 *
 * Creation Date : 20-01-2017
 *
 * Last Modified : Fri Jan 20 21:35:30 2017
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
    ListNode* insertionSortList(ListNode* head) {
        
        if(!head || !head->next) return head;
        
        ListNode *newHead = new ListNode(-1);
        ListNode *curNode = head->next, *tail = head;
        while(curNode){
            insertNode(newHead, tail);
            tail = curNode;
            curNode = curNode->next;
        }
        insertNode(newHead, tail);
        
        return newHead->next;
        
    }
    
private:    
    void insertNode(ListNode* newHead, ListNode* tail){
        
        ListNode* ptr1 = newHead, *ptr2=newHead->next;
        while(ptr2 && ptr2->val < tail->val){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        // Insert
        ptr1 ->next = tail;
        tail->next = ptr2;
        
    }
    
};


// Combine the two parts
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
    ListNode* insertionSortList(ListNode* head) {
        
        if(!head || !head->next) return head;
        ListNode *newHead = new ListNode(-1);
        newHead->next = head;
        ListNode *pre = newHead;
        ListNode *curNode = head;
        while(curNode){
            
            if(curNode->next && curNode->val > curNode->next->val){
                
                while(pre->next && curNode->next->val > pre->next->val){
                    pre = pre->next;
                }
                
                ListNode* tmp = pre->next;
                pre->next = curNode->next;
                curNode->next = curNode->next->next;
                pre->next->next = tmp;
                
                pre = newHead;
                
            }
            else curNode = curNode->next;
        }
        return newHead->next;
        
    }
    
    
};

