/**************************************************************************
 * File Name : 366-FindLeavesOfBinaryTree.cpp
 *
 * Purpose :
 *
 * Creation Date : 22-02-2017
 *
 * Last Modified : Wed Feb 22 15:33:32 2017
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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        dfs(res, root);
        return res;
    }
private:
    int dfs(vector<vector<int>>& res, TreeNode* root){
        if(!root) return 0;
        int level = max(dfs(res, root->left), dfs(res, root->right)) + 1;
        if (level > res.size()) res.push_back(vector<int> {});
        res[level-1].push_back(root->val);
        return level;
    }
    
};
