/**************************************************************************
 * File Name : 94-BinaryTreeInorderTraversal.cpp
 *
 * Purpose :
 *
 * Creation Date : 24-01-2017
 *
 * Last Modified : Tue Jan 24 18:53:55 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Iterative solution  using stack
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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> inorder(0);
        //if(!root) return inorder;
        
        stack<TreeNode*> to_be_checked;
        TreeNode* p = root;
        while(p){
            to_be_checked.push(p);
            p = p->left;
        }
        
        while(!to_be_checked.empty()){
            p = to_be_checked.top();
            to_be_checked.pop();
            
            inorder.push_back(p->val);
            p = p->right;
            while(p) {to_be_checked.push(p); p=p->left;}
        }
        
        return inorder;
        
    }
};

// Combine the while loops above
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> inorder(0);
        //if(!root) return inorder;
        
        stack<TreeNode*> to_be_checked;
        TreeNode* p = root;

        while(!to_be_checked.empty() || p){
            if(p){
                to_be_checked.push(p);
                p = p->left;
            }
            else{
                p = to_be_checked.top();
                to_be_checked.pop();
                inorder.push_back(p->val);
                p = p ->right;
            }
            
        }
        
        return inorder;
        
    }
};

// Morris traversal
