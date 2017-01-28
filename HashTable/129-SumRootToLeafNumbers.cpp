/**************************************************************************
 * File Name : 129-SumRootToLeafNumbers.cpp
 *
 * Purpose :
 *
 * Creation Date : 27-01-2017
 *
 * Last Modified : Fri Jan 27 18:29:01 2017
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
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        string pathSum;
        int sum = 0;
        sumHelper(root, pathSum, sum);
        return sum;
    }
    
private:
    void sumHelper(TreeNode* root, string& pathSum, int& sum){
        pathSum += to_string(root->val);
        if(!root->left && !root->right) {
            int tmp;
            istringstream(pathSum) >> tmp;
            sum += tmp;
        }
        if(root->left) sumHelper(root->left, pathSum, sum);
        if(root->right) sumHelper(root->right, pathSum, sum);
        pathSum.pop_back();
    }
};

// Conciser solution
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        return sumHelper(root, 0);
    }
    
private:
    int sumHelper(TreeNode* root, int sum){
        if(!root) return 0;
        sum = sum*10 + root->val;
        if(!root->left && !root->right) {
            return sum;
        }
        return sumHelper(root->left, sum) + sumHelper(root->right, sum);
    }
};
