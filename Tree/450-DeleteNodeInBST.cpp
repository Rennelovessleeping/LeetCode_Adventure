/**************************************************************************
 * File Name : 450-DeleteNodeInBST.cpp
 *
 * Purpose :
 *
 * Creation Date : 25-01-2017
 *
 * Last Modified : Wed Jan 25 19:32:48 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val == key){
            if(!root->right){
                TreeNode* l = root->left;
                delete root;
                return l;
            }
            else{
                TreeNode* r = root->right;
                while(r->left) r = r->left;
                swap(root->val, r->val);
            }
            
        }
        
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        
        return root;
    }

};
