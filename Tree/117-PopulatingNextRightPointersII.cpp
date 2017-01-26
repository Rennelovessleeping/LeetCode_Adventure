/**************************************************************************
 * File Name : 117-PopulatingNextRightPointersII.cpp
 *
 * Purpose :
 *
 * Creation Date : 25-01-2017
 *
 * Last Modified : Wed Jan 25 21:54:08 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// BFS solution
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        TreeLinkNode *curNode=root; // BFS traveral the whole binary tree;
        TreeLinkNode *head=nullptr, *tail= nullptr;
        while(curNode){
            if(curNode->left){
                if(!tail) head = tail = curNode->left;
                else tail = tail->next = curNode->left;
            }
            if(curNode->right){
                if(!tail) head = tail = curNode->right;
                else tail = tail->next = curNode->right;
            }
            if( !(curNode=curNode->next) ){
                curNode = head; // move to next level;
                head = tail = nullptr;
            }
            
        }
        
    }
};

