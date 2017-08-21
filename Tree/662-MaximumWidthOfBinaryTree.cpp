/**************************************************************************
 * File Name : 662-MaximumWidthOfBinaryTree.cpp
 *
 * Purpose :
 *
 * Creation Date : 21-08-2017
 *
 * Last Modified : Mon Aug 21 14:35:28 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Since the binary tree is full, we can use 1-based heap indexing to calculate the distance:
// for node i, its left child is 2*i and right child is 2*i+1

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
    int widthOfBinaryTree(TreeNode* root) {
        vector<int> leftmost;
        int res = 0;
        dfs(root, 0, leftmost, 1, res);
        return res;
        
    }
    void dfs(TreeNode* root, int depth, vector<int>& leftmost, int idx, int& res){
        if(!root) return;
        if(depth == leftmost.size()) leftmost.push_back(idx);
        res = max(res, idx-leftmost[depth]+1);
        dfs(root->left, depth+1, leftmost, 2*idx, res);
        dfs(root->right, depth+1, leftmost, 2*idx+1, res);
    }
};

// BFS solution:
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int res = 0;
        if(!root) return res;
        
        int depth = 0;
        vector<int> leftmost;
        queue<pair<TreeNode*, int>> q; // {node:heap idx}
        q.push({root, 1});
        
        while(!q.empty()) {
            int len = q.size();
            for(int i=0; i<len ;i++) {
                auto tmp = q.front().first; 
                int idx = q.front().second;
                q.pop();
                
                if(i==0) leftmost.push_back(idx);
                res = max(res, idx - leftmost[depth] + 1);
                if(tmp->left) q.push({tmp->left, 2*idx});
                if(tmp->right) q.push({tmp->right, 2*idx+ 1});
            }
            depth++;
        }
        
        return res;
        
    }
};
