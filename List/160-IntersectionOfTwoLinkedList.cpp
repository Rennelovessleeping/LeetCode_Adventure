/**************************************************************************
 * File Name : 160-IntersectionOfTwoLinkedList.cpp
 *
 * Purpose :
 *
 * Creation Date : 01-02-2017
 *
 * Last Modified : Wed Feb  1 21:07:56 2017
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        unordered_set<ListNode*> setA;
        while(headA){
            setA.insert(headA);
            headA = headA->next;
        }
        
        while(headB){
            if (setA.find(headB) != setA.end()) return headB;
            headB = headB->next;
        }
        
        return nullptr;
    }
};

// The idea of better solution is use B to complement A, as well as A to B, to make two lists the same length;
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *pA = headA, *pB = headB;
        while(pA != pB){
            pA = !pA ? headB : pA->next;
            pB = !pB ? headA : pB->next;
        }
        return pA;
    }
};
