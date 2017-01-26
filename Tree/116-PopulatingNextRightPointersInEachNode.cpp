/**************************************************************************
 * File Name : 116-PopulatingNextRightPointersInEachNode.cpp
 *
 * Purpose :
 *
 * Creation Date : 25-01-2017
 *
 * Last Modified : Wed Jan 25 21:53:26 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// DFS solution
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
        TreeLinkNode* leftMost = root, *cur;
        while(leftMost->left){
            cur = leftMost;
            while(cur){
                cur->left->next = cur->right;
                if(cur->next) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            leftMost = leftMost->left; // Move on to next level;
        }
    }
};

