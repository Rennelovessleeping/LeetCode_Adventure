/**************************************************************************
 * File Name : 138-CopyListWithRandomPointer.cpp
 *
 * Purpose :
 *
 * Creation Date : 30-01-2017
 *
 * Last Modified : Mon Jan 30 21:46:58 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<RandomListNode*, RandomListNode*> copyList;
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Naively looping throught the list might copy the node multiple times;
        if(!head) return nullptr;
        if(copyList.find(head)==copyList.end()){
            copyList[head] = new RandomListNode(head->label);
            copyList[head]->next = copyRandomList(head->next);
            copyList[head]->random = copyRandomList(head->random);
        }
        return copyList[head];
    }
};


