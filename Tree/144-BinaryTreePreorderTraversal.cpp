/**************************************************************************
 * File Name : 144-BinaryTreePreorderTraversal.cpp
 *
 * Purpose :
 *
 * Creation Date : 25-01-2017
 *
 * Last Modified : Wed Jan 25 16:55:27 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Iterative solution
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(!root) return preorder;
        
        stack<TreeNode*> nodeStack;
        TreeNode* p = root;
        
        while(p || !nodeStack.empty()){
            if(p){
                preorder.push_back(p->val);
                if(p->right) nodeStack.push(p->right);
                p = p->left;
            }
            else{
                p = nodeStack.top();
                nodeStack.pop();
            }
        }
        
        return preorder;
    }
};

// Consice solution
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(!root) return preorder;
        
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        
        while(!nodeStack.empty()){
            TreeNode* p = nodeStack.top();
            preorder.push_back(p->val);
            nodeStack.pop();
            
            if(p->right) nodeStack.push(p->right);
            if(p->left)  nodeStack.push(p->left);
        }
        
        return preorder;
    }
};
