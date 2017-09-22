/**************************************************************************
 * File Name : 652-FindDuplicateSubtrees.cpp
 *
 * Purpose :
 *
 * Creation Date : 22-09-2017
 *
 * Last Modified : Fri Sep 22 15:18:14 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Serialize tree + hash table
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        dfs(root, res);
        return res;
    }
    
    unordered_map<string, int> mp;
    string dfs(TreeNode* root, vector<TreeNode*>& res) { // serialize subtree rooted at root node
        if(!root) return "#";
        string tmp = to_string(root->val) + ',' + dfs(root->left, res) + ',' + dfs(root->right, res);
        if(mp[tmp]++ == 1) res.push_back(root);
        return tmp;
    }
};
