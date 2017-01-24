/**************************************************************************
 * File Name : 102-BSTLevelOrderTraversal.cpp
 *
 * Purpose :
 *
 * Creation Date : 11-01-2017
 *
 * Last Modified : Tue Jan 24 14:16:36 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// DFS solution
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        helper(root, 0);
        return traversal;
    }
    
private:
    vector<vector<int>> traversal;
    void helper(TreeNode* root, int depth){
        if(!root) return;
        if(traversal.size()==depth) traversal.push_back(vector<int> ());
        traversal[depth].push_back(root->val);
        helper(root->left, depth+1);
        helper(root->right, depth+1);
    }
    
};

// BFS solution using queue
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> traversal;
        int depth=0;
        queue<TreeNode*> q;
        if(root) q.push(root);
        
        while(!q.empty()){
            traversal.push_back(vector<int> ());
            for(int i=0, len=q.size(); i<len; i++){
                TreeNode* p = q.front();
                q.pop();
                traversal[depth].push_back(p->val);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            
            depth++;
        }
        
        return traversal;
    }
};

