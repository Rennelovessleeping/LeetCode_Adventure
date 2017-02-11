/**************************************************************************
 * File Name : 23-MergeKSortedList.cpp
 *
 * Purpose :
 *
 * Creation Date : 10-02-2017
 *
 * Last Modified : Fri Feb 10 23:40:43 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Use heap
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode *newhead = new ListNode(-1), *ptr = newhead, *nextNode;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        
        ListNode* tmp;
            
        for(int i=0; i<lists.size();i++){
            if(lists[i]) pq.push(make_pair(lists[i]->val, lists[i]));
        }

        while(!pq.empty()){
            tmp = pq.top().second;
            ptr->next = tmp;
            ptr = ptr->next;
            pq.pop();
            if(tmp->next) pq.push(make_pair(tmp->next->val, tmp->next));
        }
        
        return newhead->next;
        
    }
};

// Use merge two sorted list:
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        
        while(lists.size()>1){
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        
        return lists[0];
        
    }
    
private:
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2){
        if(!l1 && !l2) return nullptr;
        if(!l1) return l2;
        if(!l2) return l1;
        
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};



class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode *newhead = new ListNode(-1), *ptr = newhead, *nextNode;
        
        while(true){
            int cur = INT_MAX;
            int nextIdx = -1;
            for(int i=0; i<lists.size();i++){
                if(lists[i] && lists[i]->val < cur) {
                    cur = lists[i]->val;
                    nextNode = lists[i]; 
                    nextIdx = i;
                }
            }
            
            if(nextIdx == -1) return newhead->next; 
            ptr->next = nextNode;
            lists[nextIdx] = nextNode->next;
            nextNode->next = nullptr;
            ptr = ptr->next;
        }
        
    }
};

