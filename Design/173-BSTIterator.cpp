/**************************************************************************
 * File Name : 173-BSTIterator.cpp
 *
 * Purpose :
 *
 * Creation Date : 13-02-2017
 *
 * Last Modified : Mon Feb 13 19:47:30 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Solution using stack
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        pushAllLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *p = stk.top();
        stk.pop();
        pushAllLeft(p->right);
        return p->val;
    }

private:
    stack<TreeNode*> stk;
    void pushAllLeft(TreeNode *root){
        while(root){
            stk.push(root);
            root = root->left;
        }
    }
};


/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */


