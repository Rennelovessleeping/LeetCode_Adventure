/**************************************************************************
 * File Name : 25-ReverseNodesInKGroup.cpp
 *
 * Purpose :
 *
 * Creation Date : 17-02-2017
 *
 * Last Modified : Fri Feb 17 21:35:59 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *cur = head;
        int cnt = 0;
        while(cur && cnt!=k) {
            cur = cur->next;
            cnt++;
        } // After the loop, cur points to the k+1'th node;
        
        if(cnt == k){
            cur = reverseKGroup(cur, k); // reverse the following part
            while(cnt-->0){ // reverse k node;
                ListNode *tmp = head->next;
                head->next = cur;
                cur = head;
                head = tmp;
            }
            head = cur;
        }
        return head;
    }
};

