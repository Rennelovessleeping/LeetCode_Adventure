/**************************************************************************
 * File Name : 257-BinaryTreePaths.cpp
 *
 * Purpose :
 *
 * Creation Date : 23-01-2017
 *
 * Last Modified : Mon Jan 23 22:22:15 2017
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> allPath;
        if(!root) return allPath;
        
        genPath(allPath, "", root);
        return allPath;
    }

private:
    void genPath(vector<string>& allPath, string parentPath, TreeNode *root){
        if(!root->left && !root->right) { 
            allPath.push_back(parentPath + to_string(root->val));
            return;
        }
        
        if(root->left) genPath(allPath, parentPath + to_string(root->val) + "->", root->left);
        if(root->right) genPath(allPath, parentPath + to_string(root->val) + "->", root->right);
    }
    
};


