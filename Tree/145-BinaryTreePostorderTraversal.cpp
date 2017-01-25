/**************************************************************************
 * File Name : 145-BinaryTreePostorderTraversal.cpp
 *
 * Purpose :
 *
 * Creation Date : 24-01-2017
 *
 * Last Modified : Tue Jan 24 18:54:41 2017
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
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> postorder;
        TreeNode *p = root;
        TreeNode *last = nullptr;
        stack<TreeNode*> to_be_checked;
        
        while(!to_be_checked.empty() || p){
            if(p){
                to_be_checked.push(p);
                p = p->left;
            }
            else{
                TreeNode* topNode = to_be_checked.top();
                // When go back to parent node, we have to make sure that we have not push parent->right before;
                if(topNode->right && last!=topNode->right) p = topNode->right;
                else{
                    postorder.push_back(topNode->val);
                    last = topNode;
                    to_be_checked.pop();
                    
                }
                
            }
            
        }
        
        return postorder;
    }
};
