/**************************************************************************
 * File Name : 148-SortList.cpp
 *
 * Purpose :
 *
 * Creation Date : 02-01-2017
 *
 * Last Modified : Mon Jan  2 23:48:41 2017
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
 // Bottom-up Divide and Conquer
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        
        int len=0;
        ListNode *cur = head;
        while(cur){ 
            len++; 
            cur = cur->next;
        }

        ListNode newHead(-1); newHead.next = head;
        ListNode *left, *right, *tail;
        
        
        for(int blockSize = 1; blockSize < len; blockSize <<= 1){
            cur = newHead.next; // NOT cur = head !!
			tail = &newHead; // end of sorted region
            while(cur){
                left = cur;
                right = divide(left,blockSize);
                cur = divide(right, blockSize);
                tail = mergeSort(left, right, tail);
            }
            cout << head->val << endl;
        }
        
        return newHead.next;
        
    }
    
private:
    ListNode* divide(ListNode* head, int blockSize){ 
        // return head of right list and end the left list with NULL end. The divide function literally cut up the original list
        for(int i=1;i<blockSize && head;i++) head = head->next;
        if(!head) return head;
        ListNode* right = head->next;
        head->next = NULL;
        return right;
    }
    
    ListNode* mergeSort(ListNode* left, ListNode* right, ListNode* tail){// Append the sorted list to tail
        while(left && right){
            if(left->val < right->val){
                tail->next = left;
                left = left->next;
            }
            else{
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        
        tail->next = left ? left:right; 
        while(tail->next) tail = tail->next;
        return tail;
    }
    
};
