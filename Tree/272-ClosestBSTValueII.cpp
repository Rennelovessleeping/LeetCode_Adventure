/**************************************************************************
 * File Name : 272-ClosestBSTValueII.cpp
 *
 * Purpose :
 *
 * Creation Date : 19-04-2017
 *
 * Last Modified : Wed Apr 19 22:20:10 2017
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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        stack<int> pre, suc;
        
        inorder(root, pre, target, false);
        inorder(root, suc, target, true);
        
        while(k-->0) {
            if(pre.empty()) {
                res.push_back(suc.top());
                suc.pop();
            }
            else if(suc.empty()) {
                res.push_back(pre.top());
                pre.pop();
            }
            else if(fabs(pre.top() - target) < fabs(suc.top() - target)) {
                res.push_back(pre.top());
                pre.pop();
            }
            else{
                res.push_back(suc.top());
                suc.pop();
            }
        }
        
        return res;
    }
    
    void inorder(TreeNode* root, stack<int>& stk, double target, bool reverse) {
        if(!root) return;
        
        inorder(reverse ? root->right : root->left, stk, target, reverse);
        if((reverse && root->val <= target) || (!reverse && root->val > target)) return;
        stk.push(root->val);
        inorder(reverse ? root->left : root->right, stk, target, reverse);
    }
    
};
