/**************************************************************************
 * File Name : 314-BinaryTreeVerticalOrderTraversal.cpp
 *
 * Purpose :
 *
 * Creation Date : 09-02-2017
 *
 * Last Modified : Thu Feb  9 22:11:30 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// BFS + HashTable
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
    vector<vector<int>> verticalOrder(TreeNode* root) { // BFS
        
        vector<vector<int>> res;
        if(!root) return res;
        
        map<int, vector<int>> map;
        queue<pair<int, TreeNode*>> pq;
        pq.push(make_pair(0, root));
        
        while(!pq.empty()){
            int col = pq.front().first;
            TreeNode* node = pq.front().second;
            pq.pop();
            map[col].push_back(node->val);
            
            if(node->left) pq.push(make_pair(col-1, node->left));
            if(node->right) pq.push(make_pair(col+1, node->right)); 
        }
        
        for(auto m:map) res.push_back(m.second); 
        return res;
    }
    
    
};

