/**************************************************************************
 * File Name : 99-RecoverBST.cpp
 *
 * Purpose :
 *
 * Creation Date : 23-02-2017
 *
 * Last Modified : Thu Feb 23 13:26:37 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> res;
        TreeNode *prev1 = nullptr, *prev2 = nullptr;
        TreeNode *wrong1 = dfs_large(root, prev1), *wrong2 = dfs_small(root, prev2); 
        if(wrong1 && wrong2) swap(wrong1->val, wrong2->val);
    }
    
private:    
    TreeNode* dfs_large(TreeNode* root, TreeNode*& prev){
        if(!root) return nullptr;
        TreeNode *tmp = dfs_large(root->left, prev); 
        if(tmp) return tmp;  
        else if (prev && root->val <= prev->val) return prev;
        else {
            prev = root;
            return dfs_large(root->right, prev);
        }
    }
    
    TreeNode* dfs_small(TreeNode* root, TreeNode*& prev){
        if(!root) return nullptr;
        TreeNode* tmp = dfs_small(root->right, prev);
        if(tmp) return tmp;
        else if(prev && root->val >= prev->val) return prev;
        else{
            prev = root;
            return dfs_small(root->left, prev);
        }
    }
};

// Conciser solution:
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
    TreeNode *wrong1 = nullptr, *wrong2 = nullptr;
    void recoverTree(TreeNode* root) {
        TreeNode *prev = nullptr;
        dfs(root, prev);
        swap(wrong1->val, wrong2->val);
    }
private: 
    void dfs(TreeNode* root, TreeNode*& prev){
        if(!root) return;
        dfs(root->left, prev);
        if(!wrong1 && prev && prev->val >= root->val) wrong1 = prev;
        if(wrong1 && prev && prev->val >= root->val) wrong2 = root;
        prev = root;
        dfs(root->right, prev);
    }    
};
