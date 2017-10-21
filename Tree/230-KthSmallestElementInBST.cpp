/**************************************************************************
 * File Name : 230-KthSmallestElementInBST.cpp
 *
 * Purpose :
 *
 * Creation Date : 25-01-2017
 *
 * Last Modified : Sat Oct 21 13:29:02 2017
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
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
    
    int inorder(TreeNode*root, int& k){
        if (root){
            int tmp = inorder(root->left, k); //traversal the left subtree;
            return !k ? tmp : !--k ? root->val : inorder(root->right,k);
        }
        return 0;
    }
    
};

// iterative solution using stack
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;        
        while(root || !stk.empty()) {
            while(root) {
                stk.push(root);
                root = root->left;
            }
            
            root = stk.top(); stk.pop();
            if(--k == 0) return root->val;
            root = root->right;
        }
        
        return -1;
    }
};
