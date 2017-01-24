/**************************************************************************
 * File Name : 107-BSTLevelOrderTraversalII.cpp
 *
 * Purpose :
 *
 * Creation Date : 11-01-2017
 *
 * Last Modified : Tue Jan 24 14:28:41 2017
 *
 * Created By :  
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return traversal;
        helper(root, 0); 
        return traversal;
    }
    
private:
    vector<vector<int>> traversal;
    void helper(TreeNode *root, int depth){
        if(!root) return;
        if(traversal.size()==depth) traversal.insert(traversal.begin(), vector<int>());
        
        traversal[traversal.size()-1-depth].push_back(root->val);
        helper(root->left, depth+1);
        helper(root->right, depth+1);
    }

};

// Naively reverse Q102's solution.
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return traversal;
        helper(root, 0); 
        return vector<vector<int>> (traversal.rbegin(), traversal.rend());
    }
    
private:
    vector<vector<int>> traversal;
    void helper(TreeNode *root, int depth){
        if(!root) return;
        if(traversal.size()==depth) traversal.push_back(vector<int> ());
        
        traversal[depth].push_back(root->val);
        helper(root->left, depth+1);
        helper(root->right, depth+1);
    }

};


//BFS solution
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> traversal;
        queue<TreeNode*> q;
        if(root) q.push(root);
        
        while(!q.empty()){
            traversal.insert(traversal.begin(), vector<int>());
            for(int i=0, len=q.size(); i<len; i++){
                TreeNode* p = q.front();
                q.pop();
                traversal[0].push_back(p->val);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
        }
        
        return traversal;
    }
};
