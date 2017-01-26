/**************************************************************************
 * File Name : 114-FlatternBinaryTreeToLinkedList.cpp
 *
 * Purpose :
 *
 * Creation Date : 25-01-2017
 *
 * Last Modified : Wed Jan 25 22:53:27 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Non recursive solution through right rotating the tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* curNode = root;
        while(curNode){
            if(curNode -> left){
                TreeNode* p = curNode->left;
                while(p->right) p = p->right;
                p->right = curNode->right;
                curNode->right = curNode->left;
                curNode->left = nullptr;
            }
            curNode = curNode->right;
        }
        
    }
    
};

// Inverse pre-order solution;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* prev = nullptr;
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
    
};
