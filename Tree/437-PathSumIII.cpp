/**************************************************************************
 * File Name : 437-PathSumIII.cpp
 *
 * Purpose :
 *
 * Creation Date : 23-01-2017
 *
 * Last Modified : Mon Jan 23 23:33:23 2017
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
    int pathSum(TreeNode* root, int sum) {
        
        dfs(root, sum);
        return counter;
    }
    
private:
    int counter = 0;
    void dfs(TreeNode * root, int sum){
        if(!root) return;
        genPath(root->val, root, sum);
        dfs(root->left, sum);
        dfs(root->right, sum);
    }
    
    void genPath(int curSum, TreeNode* root, int sum){
        
        if (curSum == sum) counter++;
        if(!root->left && !root->right) return;
        
        if(root->left) genPath(curSum+root->left->val, root->left, sum);
        if(root->right) genPath(curSum+root->right->val, root->right, sum);
        
    }

};

// Consice version
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        return sumUp(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

private:
    int sumUp(TreeNode* root, int curSum, int sum){ // Traverse the part below root
        if(!root) return 0;
        curSum += root->val;
        return (curSum == sum) + sumUp(root->left, curSum, sum) + sumUp(root->right, curSum, sum);
    }

};
