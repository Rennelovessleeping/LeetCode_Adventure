/**************************************************************************
 * File Name : 103-BinaryTreeZigzagLevelOrderTraversal.cpp
 *
 * Purpose :
 *
 * Creation Date : 24-01-2017
 *
 * Last Modified : Tue Jan 24 14:46:52 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// BFS solution
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> traversal;
        int depth = 0;
        queue<TreeNode*> q;
        
        if(root) q.push(root);
        while(!q.empty()){
            traversal.push_back(vector<int>()); 
            for(int i=0, len=q.size(); i<len; i++) {
                TreeNode* p=q.front();
                q.pop();
                
                if(depth%2==0) traversal[depth].push_back(p->val);
                else traversal[depth].insert(traversal[depth].begin(), p->val);
                
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
                
            }
            
            depth++;
        }
        
        return traversal;
    }
};

