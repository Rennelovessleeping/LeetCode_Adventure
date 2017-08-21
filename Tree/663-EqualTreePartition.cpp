/**************************************************************************
 * File Name : 663-EqualTreePartition.cpp
 *
 * Purpose :
 *
 * Creation Date : 21-08-2017
 *
 * Last Modified : Mon Aug 21 13:49:06 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// If we find a subtree with sum == total_sum/2, then we are done
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
    bool checkEqualTree(TreeNode* root) {
        multiset<long> subtree_sums;
        long sum = helper(root, subtree_sums);
        return sum%2 == 0 && subtree_sums.size() > 1 && subtree_sums.find(sum/2) != subtree_sums.end();
    }
    
    long helper(TreeNode* root, multiset<long>& subtree_sums) {
        if(!root) return 0;
        return *subtree_sums.insert(root->val + helper(root->left, subtree_sums) + helper(root->right, subtree_sums));
    }
};
