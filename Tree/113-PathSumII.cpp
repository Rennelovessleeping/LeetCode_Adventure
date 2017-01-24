/**************************************************************************
 * File Name : 113-PathSumII.cpp
 *
 * Purpose :
 *
 * Creation Date : 23-01-2017
 *
 * Last Modified : Mon Jan 23 22:46:21 2017
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
    vector<vector<int>> allPath;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return allPath;
        genPath(0, vector<int>(0), root, sum);
        return allPath;
    }
    
private:
    void genPath(int curSum, vector<int> parentPath, TreeNode* root, int sum){
        if(!root->left && !root->right && (curSum + root->val) == sum ){
            parentPath.push_back(root->val);
            allPath.push_back(parentPath);
        }
        curSum += root->val;
        parentPath.push_back(root->val);
        if(root->left) genPath(curSum, parentPath, root->left, sum);
        if(root->right) genPath(curSum, parentPath, root->right, sum);
    }

};

//Backtracing solution?
