/**************************************************************************
 * File Name : 536-ConstructBinaryTree.cpp
 *
 * Purpose :
 *
 * Creation Date : 17-04-2017
 *
 * Last Modified : Mon Apr 17 20:42:41 2017
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
    TreeNode* str2tree(string s) { // s from left->right : preorder traversal
        stack<TreeNode*> stk;
        
        for(int i=0, j=0; i<s.length(); i++, j=i) {
            if(isdigit(s[i]) || s[i] == '-') {
                while(i+1 < s.length() && isdigit(s[i+1])) i++;
                TreeNode* cur = new TreeNode(stoi(s.substr(j, i-j+1)));
                if(!stk.empty()) {
                    TreeNode* tmp = stk.top();
                    if(!tmp->left) tmp->left = cur;
                    else tmp->right = cur;
                }
                stk.push(cur);
            }
            else if(s[i] == ')') stk.pop();
        }
        
        return stk.empty() ? nullptr : stk.top();
    }
};
